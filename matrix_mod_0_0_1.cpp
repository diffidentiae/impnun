#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class matrix_t
{
	int ** data_;
	unsigned int rows_;
	unsigned int collumns_;

public:

	matrix_t(unsigned int rows, int collumns)
	{
		rows_ = rows;
		collumns_ = collumns;
		data_ = new int*[rows];
		for (unsigned int i = 0;i<rows;i++)
		{
			data_[i] = new int[collumns];
			for (unsigned int j = 0; j < collumns_; j++)
			{
				data_[i][j] = 0;
			}
		}
	}

	matrix_t()
	{
		rows_ = 0;
		collumns_ = 0;
		data_ = nullptr;
	}

	~matrix_t()
	{
		for (unsigned int i = 0;i<rows_;i++)
		{
			delete[] data_[i];
		}
		delete[] data_;
	}

	matrix_t(matrix_t const & other)
	{
		data_ = new int *[other.rows_];
		for (unsigned int i = 0; i < other.rows_; i++)
		{
			data_[i] = new int[other.collumns_];
			for (unsigned int j = 0; j < other.collumns_; j++)
			{
				data_[i][j] = other.data_[i][j];
			}
		}
		rows_ = other.rows_;
		collumns_ = other.collumns_;
	}

	matrix_t & operator =(matrix_t const & other)
	{
		if (this != &other)
		{
			for (unsigned int i = 0;i<rows_;i++)
			{
				delete[] data_[i];
			}
			delete[] data_;

			data_ = new int *[other.rows_];
			for (unsigned int i = 0; i < other.rows_; i++)
			{
				data_[i] = new int[other.collumns_];
				for (unsigned int j = 0; j < other.collumns_; j++)
				{
					data_[i][j] = other.data_[i][j];
				}
			}
			rows_ = other.rows_;
			collumns_ = other.collumns_;
		}

		return *this;
	}

	matrix_t add(matrix_t const & other) const
	{
		matrix_t result(rows_, collumns_);
		for (unsigned int i = 0; i < rows_; i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				result.data_[i][j] = data_[i][j] + other.data_[i][j];
			}
		}
		return result;
	}

	matrix_t sub(matrix_t const & other) const
	{
		matrix_t result(rows_, collumns_);
		for (unsigned int i = 0;i<rows_;i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				result.data_[i][j] = data_[i][j] - other.data_[i][j];
			}
		}
		return result;
	}

	matrix_t mul(matrix_t const & other) const
	{
		matrix_t result(rows_, other.collumns_);
		for (unsigned int i = 0;i<rows_;i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				int sum = 0;
				for (unsigned int k = 0;k<collumns_;k++)
				{
					sum += data_[i][k] * other.data_[k][j];
				}
				result.data_[i][j] = sum;
			}
		}
		return result;
	}

	matrix_t trans() const
	{
		matrix_t result(collumns_, rows_);
		for (unsigned int i = 0;i<rows_;i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				result.data_[j][i] = data_[i][j];
			}
		}
		return result;
	}

	std::ifstream & read(std::ifstream & stream)
	{
		for (unsigned int i = 0;i<rows_;i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				if (!(stream >> data_[i][j]))
				{
					cout << "An error has occurred while reading input data";
				}
			}
		}
		return stream;
	}

	std::ostream & write(std::ostream & stream) const
	{
		for (unsigned int i = 0;i<rows_;i++)
		{
			for (unsigned int j = 0;j<collumns_;j++)
			{
				stream << data_[i][j] << " ";
			}
			stream << endl;
		}
		return stream;
	}
};

bool RnCinput(std::ifstream & stream, unsigned int & rows, unsigned int & collumns)
{
	char comma;
	return bool(stream >> rows >> comma >> collumns);
}

int main()
{
	string filename1, filename2;
	if (getline(cin, filename1) && (filename1.size() != 0))
	{
		ifstream file1(filename1);
		string op;
		getline(cin, op);
		unsigned int rows1, collumns1;
		switch (op[0])
		{
		case '+':
			if (getline(cin, filename2) && (filename1.size() != 0))
			{
				ifstream file2(filename2);
				unsigned int rows2, collumns2;
				if (RnCinput(file1, rows1, collumns1))
				{
					if (RnCinput(file2, rows2, collumns2))
					{
						if ((rows1 == rows2) && (collumns1 == collumns2))
						{
							matrix_t matrix1(rows1, collumns1);
							matrix_t matrix2(rows2, collumns2);
							matrix_t matrixresult(rows1, collumns1);
							matrix1.read(file1);
							matrix2.read(file2);
							matrixresult = matrix1.add(matrix2);
							matrixresult.write(cout);
						}
					}
					else
					{
						cout << "An error has occurred while reading input data";
					}
				}
				else
				{
					cout << "An error has occurred while reading input data";
				}
				file2.close();
			}
			else
			{
				cout << "An error has occurred while reading input data";
			}
			break;

		case '-':
			if (getline(cin, filename2) && (filename1.size() != 0))
			{
				ifstream file2(filename2);
				unsigned int rows2, collumns2;
				if (RnCinput(file1, rows1, collumns1))
				{
					if (RnCinput(file2, rows2, collumns2))
					{
						if ((rows1 == rows2) && (collumns1 == collumns2))
						{
							matrix_t matrix1(rows1, collumns1);
							matrix_t matrix2(rows2, collumns2);
							matrix_t matrixresult(rows1, collumns1);
							matrix1.read(file1);
							matrix2.read(file2);
							matrixresult = matrix1.sub(matrix2);
							matrixresult.write(cout);
						}
					}
					else
					{
						cout << "An error has occurred while reading input data";
					}
				}
				else
				{
					cout << "An error has occurred while reading input data";
				}
				file2.close();
			}
			else
			{
				cout << "An error has occurred while reading input data";
			}
			break;

		case '*':
			if (getline(cin, filename2) && (filename1.size() != 0))
			{
				ifstream file2(filename2);
				unsigned int rows2, collumns2;
				if (RnCinput(file1, rows1, collumns1))
				{
					if (RnCinput(file2, rows2, collumns2))
					{
						if (collumns1 == rows2)
						{
							matrix_t matrix1(rows1, collumns1);
							matrix_t matrix2(rows2, collumns2);
							matrix_t matrixresult(rows1, collumns2);
							matrix1.read(file1);
							matrix2.read(file2);
							matrixresult = matrix1.mul(matrix2);
							matrixresult.write(cout);
						}
					}
					else
					{
						cout << "An error has occurred while reading input data";
					}
				}
				else
				{
					cout << "An error has occurred while reading input data";
				}
				file2.close();
			}
			else
			{
				cout << "An error has occurred while reading input data";
			}
			break;

		case 'T':
			if (RnCinput(file1, rows1, collumns1))
			{
				matrix_t matrix1(rows1, collumns1);
				matrix_t matrixresult(collumns1, rows1);
				matrix1.read(file1);
				matrixresult = matrix1.trans();
				matrixresult.write(cout);
			}
			else
			{
				cout << "An error has occurred while reading input data";
			}
			break;

		default:
			cout << "An error has occurred while reading input data";
		}
		file1.close();
	}
	else
	{
		cout << "An error has occurred while reading input data";
	}
}
