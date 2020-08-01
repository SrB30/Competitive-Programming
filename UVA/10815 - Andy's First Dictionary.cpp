#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string s;
    set<string>words;

    while(cin>>s)
    {
        string temp("");
        //int size = s.size();

        for(int i=0; s[i]!='\0'; i++)
        {
            if((s[i]<123 && s[i]>96) || (s[i]>64 && s[i]<91))
            {
                char c = tolower(s[i]);
                temp = temp + c;
            }
            else if(temp != "") {
                words.insert(temp);
                temp = "";
            }
        }
        if(temp != "")
                words.insert(temp);
    }

    set<string>::iterator i = words.begin();
    while(i != words.end())
    {
        cout << *i << endl;
        ++i;
    }


    return 0;
}


/*
Adventures in Disneyland
Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."
So they went home.
*/










/*#include <iostream>
#include <set>
#include <string>

using namespace std;

inline bool IsLowerCharacter(char c)
{
    return c >= 'a' && c <= 'z';
}

int main()
{
    string in;
    set<string> words;

    while (cin >> in)
    {
        int size = in.size();

        string current = "";
        for (int i = 0; i < size; ++i)
        {
            char c = tolower(in[i]);
            if (IsLowerCharacter(c))
                current += c;
            else if (current != "")
            {
                words.insert(current);
                current = "";
            }
        }
        if (current != "")
            words.insert(current);
    }

    for (set<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
        cout << *iter << '\n';


    return 0;
}
*/
