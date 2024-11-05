#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Shape
{
public:
  Shape();  // default constructor
  void setName(char n);  // set the name of the shape, S(Scissors), R(Rock), P(Paper)
  char getName();  // get the name of the shape, S(Scissors), R(Rock), P(Paper)
  void setValue(int v);  // set the corresponding value of the shape, 1(Rock), 2(Paper), 3(Scissors)
  int getValue();  // get the corresponding value of the shape, 1(Rock), 2(Paper), 3(Scissors)

private:
  char name; // name of the shape, S(Scissors), R(Rock), P(Paper)
  int value;  // corresponding value of the shape, 1(Rock), 2(Paper), 3(Scissors)
};

Shape::Shape()
{
  name = 'N';  // default name is 'N' (None)
  value = 0;  // default value is 0
}

void Shape::setName(char n)
{
  name = n;
}

char Shape::getName()
{
  return name;
}

void Shape::setValue(int v)
{
  value = v;
}

int Shape::getValue()
{
  return value;
}

// Declare the functions
void initSequence(Shape shapeSeq[], char shapeName[], int num);
void printSequence(Shape shapeSeq[], int num);
void determineWinner(Shape shape_user, Shape shape_computer, int round);

const int MAX_NUM = 20;  // maximum number of shapes in the sequence

int main()
{
  Shape shapeSeq[MAX_NUM];  // sequence of shapes

  char shapeName[3] = { 'R', 'P', 'S' };  // name of the shapes, R(Rock), P(Paper), S(Scissors)

  // ============= Generate and Print the Sequence of Shapes =============
  int num = 0;  // number of shapes in the sequence

  // read the num from the console, and check its range
  // allow the user to input the num until it is in the range 1 to 20
  cout << "Enter the num of shapes in the sequence (1 to 20): ";
  cin >> num;

  while (num < 1 || num > 20) {
    cout << "Your input number is out of range." << endl;
    cout << "Enter the num of shapes in the sequence (1 to 20): ";
    cin >> num;
  }

  // read the seed from the console and set the seed for random number generation
  int seed;  // seed for random number generation
  cout << "Enter the seed for random number generation: ";
  cin >> seed;
  srand(seed);    // set the seed for random number generation

  // initialize the sequence of randomly generated shapes
  initSequence(shapeSeq, shapeName, num);

  // print the sequence of shapes
  printSequence(shapeSeq, num);


  // ============= Start of the Game =============
  cout << "==== Let's start the game now! ====" << endl;
  
  int num_game = 0;  // number of rounds to play
  cout << "Enter the num of rounds you want to play: (1 to 20): ";
  cin >> num_game;

  while (num_game < 1 || num_game > 20) {
    cout << "Your input number is out of range." << endl;
    cout << "Enter the num of rounds you want to play: (1 to 20): ";
    cin >> num_game;
  }

  // read the seed from the console and set the seed for random number generation
  int seed_game = 0;  // seed for random number generation
  cout << "Enter the seed for the generation of computer's shapes: ";
  cin >> seed_game;
  srand(seed_game);  // set the seed for random number generation

  // initialize the shape sequence for the computer
  Shape shapeSeq_computer[MAX_NUM];  // sequence of shapes for the computer
  initSequence(shapeSeq_computer, shapeName, num_game);

  // play the game for num_game rounds
  for (int i = 0; i < num_game; i++)
  {
    int shape_value_user = 0;  // shape selected by the user
    cout << "Enter your shape (1 for Rock, 2 for Paper, 3 for Scissors): ";
    cin >> shape_value_user;
    Shape shape_user;

    /*===============================================================
    * Complete the code which plays the game for a round
    * You need to determine the shape selected by the user
    * Then, get the shape selected by the computer
    * Finally, determine the winner of the round and print the result
    * The output should be in the format:
    * Round i: User (shape_user) vs. Computer (shape_computer): Who wins
    * For example, if the user selects Rock, and the computer selects Paper, the output should be:
    * Round 1: User (R) vs. Computer (P): Computer wins
    * ===============================================================*/
    /* Complete the codes below */
    // determine the shape selected by the user
    if (shape_value_user == 1)  // Rock
    {
      shape_user.setName('R');
      shape_user.setValue(1);
    }
    else if (shape_value_user == 2)  // Paper
    {
      shape_user.setName('P');
      shape_user.setValue(2);
    }
    else if (shape_value_user == 3)  // Scissors
    {
      shape_user.setName('S');
      shape_user.setValue(3);
    }
    else  // deal with invalid input (Note: how to deal with invalid input?)
    {
      cout << "Invalid input. Please enter 1, 2, or 3." << endl;
      i--;
      continue;
    }

    // get the shape selected by the computer
    Shape shape_computer = shapeSeq_computer[i];  

    // determine the winner of the round and print the result
    determineWinner(shape_user, shape_computer, i);
  }

  return 0;
}

// randomly generates the sequence of shapes
void initSequence(Shape shapeSeq[], char shapeName[], int num)
{
  for (int i = 0; i < num; i++)  // iterate through the sequence of shapes
  {
    int j = rand() % 3;  // generate a random number in {0, 1, 2}
    shapeSeq[i].setName(shapeName[j]);  // set the name of the shape (Note: why start from 0?)
    shapeSeq[i].setValue(j + 1);  // set the value of the shape
  }
}

// prints the sequence of shapes sequentially
void printSequence(Shape shapeSeq[], int num)
{
  for (int i = 0; i < num; i++)
  {
    cout << shapeSeq[i].getName() << " (" << shapeSeq[i].getValue() << ")" << endl;
  }
  
}

// determines the winner of the round
void determineWinner(Shape shape_user, Shape shape_computer, int round)
{
  /*===============================================================
  * Complete the code which determines the winner of the round
  * The rules are as follows:
  * Rock (1) beats Scissors (3)
  * Scissors (3) beats Paper (2)
  * Paper (2) beats Rock (1)
  * If the shapes are the same, it is a tie
  * The output should be in the format:
  * Round i: User (shape_user) vs. Computer (shape_computer): Who wins
  * For example, if the user selects Rock, and the computer selects Paper, the output should be:
  * Round 1: User (R) vs. Computer (P): Computer wins
  * ===============================================================*/
  /* Complete the codes below */
  if (shape_user.getValue() == shape_computer.getValue())
  {
    cout << "Round " << round + 1 << ": User (" << shape_user.getName() << ") vs. Computer (" << shape_computer.getName() << "): Tie" << endl;
  }
  else if ((shape_user.getValue() == 1 && shape_computer.getValue() == 3) || (shape_user.getValue() == 2 && shape_computer.getValue() == 1) || (shape_user.getValue() == 3 && shape_computer.getValue() == 2))
  {
    cout << "Round " << round + 1 << ": User (" << shape_user.getName() << ") vs. Computer (" << shape_computer.getName() << "): User wins" << endl;
  }
  else
  {
    cout << "Round " << round + 1 << ": User (" << shape_user.getName() << ") vs. Computer (" << shape_computer.getName() << "): Computer wins" << endl;
  }
}
