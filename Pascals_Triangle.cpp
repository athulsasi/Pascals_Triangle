/*********************************************************************************
* File name		: Pascals_Triangle.cpp
* Author		: Athul Sasi
* Description	: Generates the Pascal's triangle for a given integer input. The
*				  number of rows is hardcoded main() method at the end of this file.
*				  Note - The question is stated further below.
* Remarks		: Compiled using Microsoft Visual Studio Express 2017 on Windows 10.
*				 (Note: C++11/14 supported compiler is required for compilation)
*********************************************************************************/

/* [QUESTION]
Given a non-negative integer 'numRows', generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it. */


#include <iostream> // for cout
#include <vector>
using namespace std;


/******************************************************************************
* Function name         : generatePascalsTriangle
* Author                : Athul Sasi
* Parameters			: [INPUT] numRows
						  Number of rows of the Pascal's triangle to be generated.
* Return value			: Pascal's triangle as a vector of integer vectors.
* Function description  : Generates Pascal's triangle for the given input
*******************************************************************************/
vector<vector<int>> generatePascalsTriangle(int numRows) {
	vector<int> vecRow;
	vector<vector <int>> vecPascal;
	if (0 == numRows) { return vecPascal; }

	// 1 row
	vecRow.push_back(1);
	vecPascal.push_back(vecRow);
	if (1 == numRows) {
		return vecPascal;
	}
	vecRow.clear();

	vector<int> vecTemp;
	for (auto i{ 1 }; i < numRows; i++) {
		vecTemp = vecPascal[i - 1];

		for (auto j{ 0 }; j <= i; j++) {  // Make each row
			if ((0 == j) || (i == j)) {
				vecRow.push_back(1); // 1 in beginning & end of row
			}
			else {
				vecRow.push_back(vecTemp[j] + vecTemp[j - 1]);
			}
		} // End of inner for loop  

		vecPascal.push_back(vecRow);
		vecRow.clear();

	} // End of outer for loop

	return vecPascal;
}


/******************************************************************************
* Function name         : displayPascalsTriangle
* Author                : Athul Sasi
* Parameters			: [INPUT] vecPascalTriangle
						  Pascal's triangle as a vector of integer vectors.
* Return value			: None
* Function description  : Displays Pascal's triangle onto the console window.
*******************************************************************************/
void displayPascalsTriangle(const vector<vector<int>> vecPascalTriangle) {

	auto nSpaceIndex {0};
	int nNumRows  = vecPascalTriangle.size();

	for (const auto &vecRow: vecPascalTriangle) { // Take each row
		
		// Insert spaces for alignment of each row
		for (auto i {0}; i < (nNumRows - nSpaceIndex); ++i) {
			cout << " ";
		}
		
		// Display values
		for (const auto &nVecElement: vecRow) { // Take each integer element in the row
			cout << nVecElement << " ";
		}
		cout << endl;
		nSpaceIndex++;

	} // End of outer for loop
	cout << endl<< endl;
}


/******************************************************************************
* Function name         : main
* Author                : Athul Sasi
* Parameters			: None
* Return value			: 0
* Function description  : Application's entry point.
*******************************************************************************/
int main() {

	// ========================================
	// NOTE - Input is a non-negative integer.
	// ========================================
	
	//auto nNumRows{ 3 }; // Test data
	//auto nNumRows{ 4 }; // Test data
	//auto nNumRows{ 5 }; // Test data
	auto nNumRows{ 6 }; // Test data
	//auto nNumRows{ 7 }; // Test data

	// Create the triangle
	vector<vector<int>> vecPascalTriangle = generatePascalsTriangle(nNumRows);

	// Display onto console
	displayPascalsTriangle(vecPascalTriangle);


	printf("\nPlease press any key to exit..\n");
	getchar(); /* Wait for input from user to exit */
	
	return 0;
}
