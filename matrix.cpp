class Matrix
{
private:
	int _r;
	int _c;
	int** _m;
public:
	void Display(int **mat, int row, int col)
	{
		cout << "Ma tran vua nhap: \n";
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cout << mat[i][j]<<"\t";
			}		cout << endl;
		}
	}
	void Create_Matrix(int **&mat, int row, int col)
	{
		int** mat1 = new int*[row];
		for (int i = 0; i < row; ++i)
		{
			mat1[i] = new int[col];
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cout << "Nhap phan tu thu " << i << " x " << j << ": ";
				cin >> mat1[i][j];
			}
		}
		mat = mat1;
	}
	void swap(int **mat, int row1, int row2, int col) // swap 2 collums of the matrix
	{
		for (int i = 0; i < col; i++)
		{
			int temp = mat[row1][i];
			mat[row1][i] = mat[row2][i];
			mat[row2][i] = temp;
		}
	}
	int Matrix_determinant(int **mat1, int n)
	{
		int **mat;
		mat = mat1;
		int num1, num2, det = 1, index, total = 1; // Initialize result   

												   // temporary array for storing row   
		int *temp = new int[n + 1];

		//loop for traversing the diagonal elements  
		for (int i = 0; i < n; i++)
		{
			index = i; // initialize the index   

					   //finding the index which has non zero value   
			while (mat[index][i] == 0 && index < n) {
				index++;

			}
			if (index == n) // if there is non zero element   
			{
				// the determinat of matrix as zero   
				continue;

			}
			if (index != i)
			{
				//loop for swaping the diagonal element row and index row   
				for (int j = 0; j < n; j++)
				{
					std::swap(mat[index][j], mat[i][j]);
				}
				//determinant sign changes when we shift rows   
				//go through determinant properties   
				det = det*pow(-1, index - i);
			}

			//storing the values of diagonal row elements   
			for (int j = 0; j < n; j++)
			{
				temp[j] = mat[i][j];

			}
			//traversing every row below the diagonal element   
			for (int j = i + 1; j < n; j++)
			{
				num1 = temp[i]; //value of diagonal element   
				num2 = mat[j][i]; //value of next row element   

								  //traversing every column of row   
								  // and multiplying to every row   
				for (int k = 0; k < n; k++)
				{
					//multiplying to make the diagonal   
					// element and next row element equal   
					mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);

				}
				total = total * num1; // Det(kA)=kDet(A);   
			}

		}

		//mulitplying the diagonal elements to get determinant   
		for (int i = 0; i < n; i++)
		{
			det = det * mat[i][i];

		}
		return (det / total); //Det(kA)/k=Det(A);   
	}
	float ** Inverse_Matrix(int **matrix, int det_matrix, int grade)
	{
		float** mat = new float*[grade];
		for (int i = 0; i < grade; ++i)
		{
			mat[i] = new float[grade];
		}

		for (int i = 0; i < grade; i++)
		{
			for (int j = 0; j < grade; j++)
			{
				mat[i][j] = matrix[i][j];
			}
		}
		float a = (float)1 / (float)det_matrix;
		
		for (int i = 0; i < grade; i++)
		{
			for (int j = 0; j < grade; j++)
			{
				mat[i][j] = matrix[i][j] * a;
			}
		}
		
		cout << "Ma tran vua nhap co nghich dao: \n";
		for (int i = 0; i < grade; ++i)
		{
			for (int j = 0; j < grade; ++j)
			{
				cout << mat[i][j];
			}	cout << endl;
		}
		return mat;
	}
	int ** Multiply_Matrix(int m, int n, int p, int **mtrx_a, int **mtrx_b)
	{
		int **result = new int*[m];
		for (int i = 0; i < m; i++)
		{
			result[i] = new int[p];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < p; j++)
			{
				for (int k = 0; k < n; k++)
				{
					result[i][j] += mtrx_a[i][k] * mtrx_b[k][j];
				}
			}
		}

		return result;
	}
	int rankOfMatrix(int **mat1, int R, int C)
	{
		int **mat;
		mat = mat1;
		int rank = C;
		for (int row = 0; row < rank; row++)
		{
			// Before we visit current row 'row', we make 
			// sure that mat[row][0],....mat[row][row-1] 
			// are 0. 

			// Diagonal element is not zero 
			if (mat[row][row])
			{
				for (int col = 0; col < R; col++)
				{
					if (col != row)
					{
						// This makes all entries of current 
						// column as 0 except entry 'mat[row][row]' 
						double mult = (double)mat[col][row] /
							mat[row][row];
						for (int i = 0; i < rank; i++)
							mat[col][i] -= mult * mat[row][i];
					}
				}
			}

			// Diagonal element is already zero. Two cases 
			// arise: 
			// 1) If there is a row below it with non-zero 
			//    entry, then swap this row with that row 
			//    and process that row 
			// 2) If all elements in current column below 
			//    mat[r][row] are 0, then remvoe this column 
			//    by swapping it with last column and 
			//    reducing number of columns by 1. 
			else
			{
				bool reduce = true;

				/* Find the non-zero element in current
				column  */
				for (int i = row + 1; i < R; i++)
				{
					// Swap the row with non-zero element 
					// with this row. 
					if (mat[i][row])
					{
						swap(mat, row, i, rank);
						reduce = false;
						break;
					}
				}

				// If we did not find any row with non-zero 
				// element in current columnm, then all 
				// values in this column are 0. 
				if (reduce)
				{
					// Reduce number of columns 
					rank--;

					// Copy the last column here 
					for (int i = 0; i < R; i++)
						mat[i][row] = mat[i][rank];
				}
				// Process this row again 
				row--;
			}
		}
	return rank;
	}
};

void display_mat(int **mat, int row, int col)
{
	cout << "Ma tran co ket qua: \n";
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << *(*(mat+i)+j) << "\t";
		}		cout << endl;
	}
}
