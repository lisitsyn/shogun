#ifndef _SVMMPI_H___
#define _SVMMPI_H___

/*#ifdef SVMMPI*/

#include "svm/SVM.h"
#include "kernel/Kernel.h"
#include "lib/common.h"
#include "svm_mpi/matrix.h"
#include "features/RealFeatures.h"

#if defined(HAVE_MPI) && !defined(DISABLE_MPI)

class CSVMMPI: public CSVM
{
 public:
  CSVMMPI();
  virtual ~CSVMMPI();
  
  virtual bool svm_train(CFeatures* train);
  virtual REAL* svm_test(CFeatures* test, CFeatures* train);
  virtual bool load(FILE* svm_file);
  virtual bool save(FILE* svm_file);
  
  static void svm_mpi_init(int argc, const char **argv); 
  static void svm_mpi_destroy(void) ;

 protected:
  unsigned svm_mpi_broadcast_Z_size(int num_cols, int num_rows, unsigned &m_last) ;
  void svm_mpi_set_Z_block(double * block, int num_cols, int start_idx, int rank) ; 
  void svm_mpi_optimize(int *labels, int num_examples, CRealFeatures * train) ;

 protected:
  unsigned m_full, m_last, m_prime;
  unsigned my_rank, num_nodes, num_rows;
  CMatrix<double> Z ;
  double svm_b, *svm_w ;
  
  CBlockCache<double> bcache_d;
  CBlockCache<int> bcache_i;
} ;
#endif
/*#endif // SVMMPI*/

#endif // _SVMMPI_H__
