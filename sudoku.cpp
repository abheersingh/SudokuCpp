#include <iostream>
using namespace std;

class Square{

public:
    int grid[9][9];
	Square();
    void getGrid();
    void getRow(int row[9], int i);
	void printGrid();
	bool checkPoint(int x, int y, int point);
	void generatePoint(int x, int y);
	void generateGrid();
    bool findZeros(int &x, int &y);
    void setGrid();
    bool solveGrid(int inputGrid[9][9] = 0);
    void solvePoint(int x, int y, int temp);
    bool solveTempGrid(int tempGrid[9][9]);
    bool checkGrid(int inputGrid[9][9]);
};

Square::Square(){
    
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
		grid[i][j] = 0;
		}
    }
}


void Square::getGrid(){

    cout << "Enter your sudoku net 1 row at a time, " << endl;
    cout << "with a space between each number. " << endl;
    cout << "For an empty box, enter a 0. " << endl;
    cout << "Enter your sudoku grid:" << endl;

    int row[9];

    for (int i = 0; i < 9; i++)
        getRow(row, i);

}

void Square::getRow(int row[9], int i){
    cin >> row[0] >> row[1] >> row[2] >> row[3] 
    >> row[4] >> row[5] >> row[6] >> row[7] >> row[8];

    for (int j = 0; j < 9; j++){
        grid[i][j] = row[j];
    }

}

void Square::printGrid(){
    cout << endl;
	for (int i = 0; i < 9; i++){
    	for (int j = 0; j < 9; j++){
    		cout << grid[i][j] << ' ';
    	}
    cout << endl;  	
    }
    cout << endl;    
}

bool Square::checkPoint(int x, int y, int point){

	bool row, column, square, check;
	for (int i = 0; i < 9; i++)
	{
		if (grid[i][y] == point)
		{
			column = false;
			return column;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (grid[x][i] == point)
		{
			row = false;
			return row;
		}
	}

	if (x < 3)
	{
		if (y < 3)
		{
		for (int i = 0; i < 3; i++){
    		for (int j = 0; j < 3; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 3 && y < 6)
    	{
    	for (int i = 0; i < 3; i++){
    		for (int j = 3; j < 6; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 6)
    	{
    	for (int i = 0; i < 3; i++){
    		for (int j = 6; j < 9; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}
    }

	else if (x >= 3 && x < 6)
	{
		if (y < 3)
		{
		for (int i = 3; i < 6; i++){
    		for (int j = 0; j < 3; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 3 && y < 6)
    	{
    	for (int i = 3; i < 6; i++){
    		for (int j = 3; j < 6; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 6)
    	{
    	for (int i = 3; i < 6; i++){
    		for (int j = 6; j < 9; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}
    }

	else if (x >= 6)
	{
		if (y < 3)
		{
		for (int i = 6; i < 9; i++){
    		for (int j = 0; j < 3; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 3 && y < 6)
    	{
    	for (int i = 6; i < 9; i++){
    		for (int j = 3; j < 6; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}

    	else if (y >= 6)
    	{
    	for (int i = 6; i < 9; i++){
    		for (int j = 6; j < 9; j++){
    			if (grid[i][j] == point)
    			{
    				square = false;
    				return square;
    			}
    		}
    	}
    	}
    }



	check = true;
	return check;
}

void Square::generatePoint(int x, int y){

	bool sentinel = true;

	while (sentinel)
	{
		int r = (arc4random_uniform(10));
		bool check = checkPoint(x, y, r);
		if (check)
		{
			grid[x][y] = r;
			return;
		}

	}

}

void Square::setGrid(){
    bool sentinel = true;
    while (sentinel){
        for(int i=60; i>0; i--)
            grid[(arc4random() %9)][(arc4random() %9)] = 0;

        printGrid();

        int tempGrid[9][9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                tempGrid[i][j] = grid[i][j];
            }
        }

        if (solveGrid(tempGrid))
            sentinel = false;
    }

//    printGrid();
}

void Square::generateGrid(){
    
    int j = 0;
    for (int i = 0; i < 9; i++){
            generatePoint(i,j);
        }
        
    int i = 0;
    for (int j = 1; j < 9; j++){
            generatePoint(i,j);
        }
    solveGrid();

}

bool Square::findZeros(int &i, int &j){
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}


bool Square::solveGrid(int inputGrid[9][9]){

    if (inputGrid != 0)
    {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                grid[i][j] = inputGrid[i][j];
            }
        }
    }

    int i,j;
    if (findZeros(i,j))
        return true;

    for (int z = 1; z <= 9; z++){
        if (checkPoint(i,j,z)){
            grid[i][j] = z;
            if (solveGrid())
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

bool Square::checkGrid(int inputGrid[9][9]){
    solveGrid();
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (inputGrid[i][j] != grid[i][j])
                    return false;
            }
        }

    return true;
}

int main()
{
    int menuChoice;

    cout << "Welcome to the C++ Sudoku Engine!" << endl;
    cout << "This program allows you to input your own sudoku grid" << endl;
    cout << "to see it's solution, or solve a sudoku generated by the " << endl;
    cout << "engine. Enter 1 to input your own sudoku or enter 2 to " << endl;
    cout << "attempt a generated sudoku." << endl;
    cin >> menuChoice;

    Square square;

    if (menuChoice == 1){
        square.getGrid();
        square.solveGrid();
        square.printGrid();
    }
    else if (menuChoice == 2){
        square.generateGrid();
        square.setGrid();

        int tempGrid[9][9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                tempGrid[i][j] = square.grid[i][j];
            }
        }

        square.getGrid();

        if (square.checkGrid(tempGrid))
            cout << "Correct Solution!" << endl;
        else
            cout << "Incorrect Solution!" << endl;

    }
    


}


