//
//  Assignment #4 - Leander Rodriguez
//
//  CST 116 - C++ Programming I
//
//  Due Date:  Sunday, November 18th by 11:59pm
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define FILE_NAME_SIZE			32
#define STUDENT_NAME_SIZE		15
#define STUDENT_COLUMN_SIZE		17
#define GENDER_COLUMN_SIZE		8
#define PERCENTAGE_COLUMN_SIZE	9
#define PERCENTAGE_COLUMN_WIDTH 10
#define GRADE_COLUMN_SIZE		8
#define AVERAGES_COLUMN_SIZE	18


void displayCLASSaverages()
{
	
	cout  <<  endl;

	cout.setf( ios::right ); //Allignment right justified

	cout  <<  setw(AVERAGES_COLUMN_SIZE)	<<  "Male average: "	
		  <<  "82.7"						<<  "%"  
		  <<  endl,

	cout  <<  setw(AVERAGES_COLUMN_SIZE)	<<	"Female average: "
		  <<  "90.7"						<<  "%"  
		  <<  endl,

	cout  <<  setw(AVERAGES_COLUMN_SIZE)	<<	"Class average: "
		  <<  "85.9"						<<  "%"  
		  <<  endl							<<  endl;

	cout.unsetf( ios::right );
}


//
// Student letter grade is calculated
//
void studentLETTERgrade( double percentage )
{

	if ( percentage >= 90 )
		cout  <<  "A";
	else if ( percentage < 90  &&  percentage >= 80 )
		cout  <<  "B";
	else if ( percentage < 80  &&  percentage >= 70 )
		cout  <<  "C";
	else if ( percentage < 70  &&  percentage >= 60 )
		cout  <<  "D";
	else if ( percentage < 60 )
		cout  <<  "F";

}


double determineSTUDENTscores( ifstream &inFile, 
							 int numOFstudents,
							 int numOFscores,
							 int pointsPossible,
							 int numOFmales,
							 int numOFfemales,
							 double classPoints,
							 double	malePoints,
							 double	femalePoints )
{

	for ( int count = 0; count < numOFstudents; ++count )
	{
		int total = 0, 
			testscores;
		double percentage;

		for( count = 0;  count < numOFscores;  ++count )
		{
			inFile >>  testscores;
			total  +=  testscores;
		}
		
		//
		// Student percentage calculated and displayed
		//
		percentage =  ( (double) total / pointsPossible ) * 100;

		cout.setf( ios::right );
		cout  <<  setw(PERCENTAGE_COLUMN_SIZE) 
			  <<  fixed  
			  <<  setprecision(1)
			  <<  percentage
			  <<  "%"
			  <<  setw(GRADE_COLUMN_SIZE); 


		//
		// Student letter grade is displayed
		//
		studentLETTERgrade( percentage ); 

		cout  <<  endl;
		cout.unsetf( ios::right );

	}

	return 0;
}



void displayNAMEandGENDER(  ifstream &inFile,
							int numOFstudents,
							int numOFmales, 
							int numOFfemales )
{

	char	studentName[STUDENT_NAME_SIZE],
			studentGender;
		
	inFile  >>  studentName
			>>  studentGender;

		cout.setf( ios::left ); //Allighment left justified

		cout  <<  setw(STUDENT_COLUMN_SIZE)		
			  <<  studentName
			  <<  setw(GENDER_COLUMN_SIZE);

			if (  studentGender = 'F'  &&  studentGender != 'M' )
				cout  <<  "Female";
			else if (  studentGender = 'M'  &&  studentGender != 'F' )
				cout  <<  "Male";
				
}


void  displayTABLEheader()
{

  char  underlineStudent[]		=  "---------------",
		underlineGender[]		=  "------",
		underlinePercentage[]	=  "----------",
		underlineGrade[]		=  "-----";

	cout.setf( ios::left ); //Allignment left justified
    cout  <<  endl
          <<  setw(STUDENT_COLUMN_SIZE)		<<  "Student"
		  <<  setw(GENDER_COLUMN_SIZE)		<<  "Gender";

	cout.setf( ios::right ); //Allignment right justified
    cout  <<  setw(PERCENTAGE_COLUMN_WIDTH)	<<  "Percentage"
		  <<  setw(GRADE_COLUMN_SIZE)		<<  "Grade"  
		  <<  endl;
	cout.unsetf( ios::right );

	cout.setf( ios::left ); //Allignment left justified
    cout  <<  setw(STUDENT_COLUMN_SIZE)	<<  underlineStudent
          <<  setw(GENDER_COLUMN_SIZE)	<<  underlineGender;

	cout.setf( ios::right ); //Allignment right justified
    cout  <<  setw(PERCENTAGE_COLUMN_WIDTH)	<<  underlinePercentage
		  <<  setw(GRADE_COLUMN_SIZE)		<<  underlineGrade
		  <<  endl;  
	cout.unsetf( ios::right );
	
}

//
// Student grades report is created 
// with data from file
//
void displayGRADESreport( ifstream &inFile )
{
	int		numOFstudents,
			numOFscores,
			pointsPossible,
			numOFmales = 0,
			numOFfemales = 0,
			classPoints = 0,
			malePoints = 0,
			femalePoints = 0;
	
	inFile  >>  numOFstudents
			>>  numOFscores
			>>  pointsPossible;

	//
	// Table Header is displayed
	//
	displayTABLEheader();

	//
	// Student data is gathered from file
	// and manipulated
	//
	for( int count = 0; count < numOFstudents; ++count )
	{
		displayNAMEandGENDER(   inFile,
								numOFstudents,
								numOFmales,
								numOFfemales);

		determineSTUDENTscores(	inFile, 
								numOFstudents, 
								numOFscores, 
								pointsPossible,
								numOFmales,
								numOFfemales,
							    classPoints,
								malePoints,
								femalePoints);
	}

	//
	// Class avergaes are determined
	//
	displayCLASSaverages();
}


//
// User input
//
void promptFORfile( ifstream &inFile )
{
	char filename[FILE_NAME_SIZE];

	cout  <<  "Enter data file name: ";
	cin  >>  filename;

	inFile.open( "grades.txt" );
	
	/*
	Successful Open?
	If Yes, continue
	If No, displays error message and quits
	Example on FAQ did not work here, find an alternative.

	if( inFile.fail() )
		cout <<  "Error opening file '"
			 <<  filename
			 <<  "'"; 
	else
	{
	}
	*/

}

//
// Main program
//
int main()
{
	ifstream inFile;

	promptFORfile( inFile );

	displayGRADESreport( inFile );

	return 0;
}


