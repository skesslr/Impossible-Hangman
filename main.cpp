#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <curses.h>

using namespace std;

int main ()
{
    
    int x = 1;
    while (x==1)
    {
        
        vector<string> dict;
        
        // enter the dictionary into the code
        string line;
        ifstream dictionary ("dictionary.txt");
        if (dictionary.is_open())
        {
            while ( getline (dictionary,line) )
            {
                dict.push_back(line);
            }
            
            dictionary.close();
        }
        
        else
        {
            cout << "ERROR: Unable to open dictionary";
            cout << endl;
            return EXIT_SUCCESS;
        }
        
        cout << "***************************************************************************" << endl;
        
        cout << " /$$   /$$                                                                " << endl;
        cout << "| $$  | $$                                                                " << endl;
        cout << "| $$  | $$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$$ " << endl;
        cout << "| $$$$$$$$ |____  $$| $$__  $$ /$$__  $$| $$_  $$_  $$ |____  $$| $$__  $$" << endl;
        cout << "| $$__  $$  /$$$$$$$| $$  \\ $$| $$  \\ $$| $$ \\ $$ \\ $$  /$$$$$$$| $$  \\ $$" << endl;
        cout << "| $$  | $$ /$$__  $$| $$  | $$| $$  | $$| $$ | $$ | $$ /$$__  $$| $$  | $$" << endl;
        cout << "| $$  | $$|  $$$$$$$| $$  | $$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$| $$  | $$" << endl;
        cout << "|__/  |__/ \\_______/|__/  |__/ \\____  $$|__/ |__/ |__/ \\_______/|__/  |__/" << endl;
        cout << "                               /$$  \\ $$                                  " << endl;
        cout << "                              |  $$$$$$/                                  " << endl;
        cout << "                              \\______/                                   " << endl << "***************************************************************************" << endl << endl;
        
        int size = 4; //default
        int c = 1;
        while (c == 1)
        {
            cout << "How many letters would you like to use? (3-6) ";
            cin >> size;
            
            if (size < 7 && size > 2)
            {
                c = 2;
            }
            else
            {
                cin.clear();
                cout << "INVALID: Please enter a number between 3 and 6" << endl;
            }
            
        }
        
        
        vector<string> pool1;
        
        // puts the dictionary into an array
        for ( int i = 0; i < dict.size(); i++ )
        {
            if (dict[i].size() == size + 1)
            {
                pool1.push_back(dict[i]);
            }
        }
        
        
        string letter = "a"; // default
        string temp;
        int guess = 0;
        vector<char> letters;
        bool alreadyRemoved = false;
        
        int y = 1;
        while (y == 1)
        {
            bool z = true;
            while (z == true)
            {
                // user enters a guess
                cout << "Guess a letter: ";
                cin >> letter;
                letter = letter[0];
                
                // ensure guess is valid
                bool duplicate = false;
                if (isalpha(letter[0]))
                {
                    for (int i = 0; i < letters.size(); i++)
                    {
                        if (letter[0] == letters[i])
                        {
                            cin.clear();
                            cout << "You already made this guess! Try again." << endl;
                            duplicate = true;
                        }
                    }
                    if (duplicate == false)
                    {
                        z = false;
                    }
                }
                else
                {
                    cin.clear();
                    cout << "INVALID: Please enter a letter" << endl;
                }
                
            }
                
            letter[0] = tolower(letter[0]);
            cout << letter[0] << endl;
            system("cls");
            
            
            
            letters.push_back(letter[0]);
            
            // check if the guess is in the list of possible words
            for (int c = 0; c < pool1.size(); c++)
            {
                
                for (int x = 0; x < pool1.size(); x++)
                {
                    // makes sure that a word with multiple instances of the same letter will not remove more than one word
                    alreadyRemoved = false;
                    temp = pool1[x];
                    
                    if( pool1.size() < 20 )
                    cout << endl;
                    
                    for (int z = 0; z < temp.size() && !alreadyRemoved ; z++)
                    {
                        if (temp[z] == letter[0])
                        {
                            
                            // removes words that contain the guessed letter without regard for order
                            long lastPosition = pool1.size() - 1;
                            
                            pool1[x] = pool1[lastPosition];
                            
                            pool1.pop_back();
                            
                            alreadyRemoved = true;
                            
                            
                        }
                        
                    }
                }
            }
            
            // displays a different image of the hangman depending on the guess number.
            guess++;
            if ( guess == 6 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |         .-`--'."<< endl;
                cout<<"| |        /Y . . Y\\"<< endl;
                cout<<"| |       //  |   |  \\\\"<< endl;
                cout<<"| |      //   | . |   \\\\"<< endl;
                cout<<"| |     ')   |   |    (`"<< endl;
                cout<<"| |          ||'||"<< endl;
                cout<<"| |          || ||"<< endl;
                cout<<"| |          || ||"<< endl;
                cout<<"| |          || ||"<< endl;
                cout<<"| |         / | | \\"<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"| `-' `-' |\"\"\"|"<< endl;
            }
            
            if ( guess == 5 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |         .-`--'."<< endl;
                cout<<"| |        /Y . . Y\\"<< endl;
                cout<<"| |       //  |   | \\\\"<< endl;
                cout<<"| |      //   | . |  \\\\"<< endl;
                cout<<"| |     ')   |   |   (`"<< endl;
                cout<<"| |          ||'"<< endl;
                cout<<"| |          || "<< endl;
                cout<<"| |          || "<< endl;
                cout<<"| |          || "<< endl;
                cout<<"| |         / | "<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"| `-'     |\"\"\"|"<< endl;
            }
            if ( guess == 4 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |         .-`--'."<< endl;
                cout<<"| |        /Y . . Y\\"<< endl;
                cout<<"| |       //  |   | \\\\"<< endl;
                cout<<"| |      //   | . |  \\\\"<< endl;
                cout<<"| |     ')   |   |   (`"<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"|         |\"\"\"|"<< endl;
            }
            if ( guess == 3 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |         .-`--'"<< endl;
                cout<<"| |        /Y . . Y"<< endl;
                cout<<"| |       //  |   |  "<< endl;
                cout<<"| |      //   | . |   "<< endl;
                cout<<"| |     ')   |   |   "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"|         |\"\"\"|"<< endl;
            }
            if ( guess == 2 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |          -`--'"<< endl;
                cout<<"| |          |. .|"<< endl;
                cout<<"| |          |   |  "<< endl;
                cout<<"| |          | . |   "<< endl;
                cout<<"| |          |   |   "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"|         |\"\"\"|"<< endl;
            }
            if ( guess == 1 )
            {
                system("cls");
                cout<<" ___________.._______"<< endl;
                cout<<"| .__________))______|"<< endl;
                cout<<"| | / /      ||"<< endl;
                cout<<"| |/ /       ||"<< endl;
                cout<<"| | /        ||.-''."<< endl;
                cout<<"| |/         |/  _  \\"<< endl;
                cout<<"| |          ||  `/,|"<< endl;
                cout<<"| |          (\\\\`_.'"<< endl;
                cout<<"| |          -`--'"<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"| |          "<< endl;
                cout<<"\"\"\"\"\"\"\"\"\"\"|         |\"\"\"|"<< endl;
            }
            
            cout << "Incorrect guesses: ";
            for (int i = 0; i < letters.size(); i++)
            {
                cout << letters[i] << ", ";
            }
            
            cout << endl;
            
            // tells the player that they have lost after 6 guesses
            if (guess == 6)
            {
                cout << "*****************************************" << endl << "You lose!!" << endl;
                cout << "The word was: " << endl;
                // locates a random word within the possible remaining words
                long randIndex = random() % pool1.size();
                cout << pool1[randIndex];
                
                y = 0;
                
            }
            
        }
        
        // clears all of the vectors in case the user wants to play again
        letters.clear();
        pool1.clear();
        dict.clear();
        
        int again;
        cout << endl << "Play again? (yes = 1, no = 2) \n    ::";
        cin >> again;
        
        if (again == 2)
        {
            system("cls");
            x = 0;
        }
        
        else
        {
            system("cls");
        }
        
    }
    
    cout << endl;
    system("pause");
    return EXIT_SUCCESS;
    
}