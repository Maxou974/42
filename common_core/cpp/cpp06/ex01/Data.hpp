#ifndef DATA_HPP
#define DATA_HPP

class Data{
	int n;
public:
	Data();
	Data(const Data &);
	Data&	operator=(const Data &);
	~Data();
};

#endif