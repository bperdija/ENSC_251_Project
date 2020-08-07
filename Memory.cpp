#include "Memory.h"

// The Memory() function is used to construct a Memory object.
// Precondition: Object of Memory created.
// Postcondition: Default object created.
Memory::Memory()
{}

// The ~Memory() function is used to destruct a Memory object.
// Precondition: Object of Memory was created.
// Postcondition: No dynamically allocated data to delete, stack variables automatically deleted
Memory::~Memory()
{}

// The get_csv_contents() function is used to get the csv_contents from the Memory class.
// Precondition: read_csv() must have been called to create a vector of the CSV file.
// Postcondition: Returns the csv_contents from Memory class. This return is used as a parameter in uintToBinary();
vector<unsigned int> Memory::get_csv_contents()
{
  return csv_contents;
}

// The read_csv() function is used to read an inputted csv file and write to the csv_contents vector in Memory.
// Precondition: A file_name variable is passed in the parameter (which includes the .csv extension), the file must be a single line .csv file with unsigned integer elements.
// Postcondition: Records each element in the chosen csv file into the vector values, and then copies that vector into the csv_contents vector in the Memory class.
void Memory::read_csv(string file_name)
{
	string temp_element;
	// define empty vectors to store values
	vector<unsigned int> values;
	string file = file_name;
	ifstream myFile;
	myFile.open(file);

	if(myFile.is_open()) // while the file is open
	{
		while(myFile.peek() != EOF)

		{
			getline(myFile, temp_element, ',');
			unsigned int temp = stoul((temp_element).c_str(), 0);
			values.push_back(temp);

		}
    myFile.close();
	}

  try
 {
   if (values.empty()) throw Exceptions("empty");
 }

 catch(Exceptions bad)
 {
   cout << "The .CSV file is " << bad.getMsg_parameter() << "!" << endl;
   exit(0);
 }

	csv_contents = values;
}
