/*
*   Storing the board using vectors, enum states identifing the blocks 
*/
#include <fstream> //working with files opening reading and writing
#include <iostream>
#include <vector>
#include <string>
#include <sstream> //Used for streaming the strings from a file
/*
    Namespaces used from std
*/
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::istringstream;
using std::cout;
using std::endl;

/*
    Declare the state of the cell (blocked or Empty)
*/
enum class State 
{
    kEmpty , 
    kObstacle
};


/*
    Parse the line from the given string
*/
vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while(sline >> n >> c && c == ',')
    {
        if(n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}


/*
    Read the file and detect the block or empty and return vector
*/
vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if(myfile)
    {
        string line;
        while(getline(myfile, line))
        {
            vector<State> row =ParseLine(line);
            board.push_back(row);
        }
    }
    return board;    
}
/*
    finding the cell value
*/
string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
        break;
    
    default:
        return "0 ";   
        break;
    }
}

/*
    Printing the path Identified from the board
*/
void PrintBoard(const vector<vector<State>> board)
{
   ofstream myFile("output.txt");
    for(int i=0;i<board.size();i++)
    {   cout << "\n";
        myFile << "\n";
        for(int j=0;j<board[i].size();j++)
        {
            
            cout << CellString(board[i][j]);
            myFile << CellString(board[i][j]);
            
        }
        
    }
    myFile.close();
}

/*
    Main Implementation
*/
int main()
{
    auto board = ReadBoardFile("1.txt");
    PrintBoard(board);
    
    return 0;
}