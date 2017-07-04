all: 
	cd cpp && $(MAKE) && cd ../cpp_wrap && node-gyp configure && node-gyp build