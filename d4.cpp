// DSPS Assignment No. 4

/*  Perform the all basic operation on the string and check given string is palindrom or not */
    
    
#include <iostream>
#include <string>
#include<stack>
using namespace std;

string s, s1, s2;  // Global variables

void dlen();
void dcpy();
void dcmp();
void drev();
void dcoct();
void doccu();

void dlen() 
{
    int len1 = 0, len2 = 0;

   
    for (int i = 0; s1[i] != '\0'; i++)   // Calculate length of s1 
    {
        len1++;
    }
    
    for (int i = 0; s2[i] != '\0'; i++)  // Calculate length of s2 
    {
        len2++;
    }

    cout << "\nThe length of first string is: " << len1 << endl;
    cout << "The length of second string is: " << len2 << endl;
}

void dcpy() 
{
    string copy = "";     // Initialize an empty string for the copy

    
    for (int i = 0; s1[i] != '\0'; i++)   // Copy s1 to copy
    {
        copy += s1[i];
    }

    cout << "\nCopied string: " << copy << endl;
}

void dcmp() 
{
    
    int len1 = 0, len2 = 0;

   
    for (int i = 0; s1[i] != '\0'; i++)   // Calculate length of s1 
    {
        len1++;
    }
    
    for (int i = 0; s2[i] != '\0'; i++)  // Calculate length of s2 
    {
        len2++;
    }
    
     if (len1 < len2) 
        {
            cout << "\nFirst string is less than second string." << endl;
            return;
        } 
        else if (len1 > len2) 
        {
            cout << "\nFirst string is greater than second string." << endl;
            return;
        }
        else
        {
            cout<<"\nStrings are equal.\n";
        }
    }

void drev() 
{
    // Reverse the first string
    int len = 0;
    
    for (int i = 0; s1[i] != '\0'; i++)   // Find the length of s1
    {
        len++;
    }

    cout << "\nReversed first string: ";
    
    for (int i = len - 1; i >= 0; i--) 
    {
        cout << s1[i];
    }
    cout << endl;

    // Reverse the second string
    len = 0;
    
    for (int i = 0; s2[i] != '\0'; i++)   // Find the length of s2
    {
        len++;
    }

    cout << "Reversed second string: ";
    
    for (int i = len - 1; i >= 0; i--) 
    {
        cout << s2[i];
    }
    cout << endl;
}

void dcoct() 
{
    string result = "";

    // Concatenate s1 and s2
    for (int i = 0; s1[i] != '\0'; i++) 
    {
        result += s1[i];
    }
    
    for (int i = 0; s2[i] != '\0'; i++) 
    {
        result += s2[i];
    }

    cout << "\nConcatenated string is: " << result << endl;
}




void doccu() 
{
    int len = 0;
    cout << "\nEnter the string: ";
    cin >> s;
    
    for (int i = 0; s[i] != '\0'; i++) 
    {
        len++;
    }

    for (int i = 0; i < len; i++) 
    {
        int count = 1;  
        
        
        bool alreadyCounted = false;
        for (int k = 0; k < i; k++) 
        {
            if (s[i] == s[k]) 
            {
                alreadyCounted = true;
                break;
            }
        }

        if (alreadyCounted) 
        {
            continue;
        }

        
        for (int j = i + 1; j < len; j++) 
        {
            if (s[i] == s[j]) 
            {
                count++;
            }
        }

        cout << s[i] << " occurs " << count << " times.\n";
    }
}


void dpali()
{
   int len3=0; 
   char st[100];
   int top=-1, i=0;
   string s3;
   
   cout<<"\nEnter the string: ";
   cin>>s3;
   
   for (int i = 0; s3[i] != '\0'; i++)   // Calculate length of s3
    {
        len3++;
    }  
    
  
    while(i<len3)
    {
	top++;
	st[top]=s3[i];
	i++;
    }
    
    bool f = true;
    
   for(int i=0; i<len3; i++)
    {
    	if(st[top] != s3[i])
    	{
    		f = false;
    		
    		break;
    		
    	}
    	  top--;
    	}
    	
    	if(f)
    	{
    	   cout<<"\nGiven string is palindrome.\n";
    	}
    	else
    	{
    	   cout<<"\nGiven string is not palindrome.\n";  
    	}
}




	
	
int main() 
{
    int ch;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    while (true) 
    {
        cout << "\nMenu:\n1. Calculate length.\n2. Copy string.\n3. Compare string.\n4. Reverse string.\n5. Concatenate string.\n6. Count Occurence.\n7. Check palindrome\n8. Exit.\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                dlen();
                break;
                
            case 2:
                dcpy();
                break;
                
            case 3:
                dcmp();
                break;
                
            case 4:
                drev();
                break;
                
            case 5:
                dcoct();
                break;
                
            case 6:
            	doccu();
            	break;
            	
            case 7:
            	dpali();
            	break;
                
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
	
	return 0;
}
