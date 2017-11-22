all:
	#
	# you must install protobuf library 3.x for this by following istructions
	# at https://github.com/google/protobuf/blob/master/src/README.md
	#
	protoc hand.proto --cpp_out=.
	g++ main.cpp hand.pb.cc -std=c++11 -lprotobuf