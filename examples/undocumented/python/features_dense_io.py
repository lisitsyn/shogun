#!/usr/bin/env python
parameter_list=[[]]

def features_dense_io():
	from shogun import RealFeatures, CSVFile
	feats=RealFeatures()
	f=CSVFile("../data/fm_train_real.dat","r")
	f.set_delimiter(" ")
	feats.load(f)
	return feats

if __name__=='__main__':
	print('Dense Real Features IO')
	features_dense_io(*parameter_list[0])
