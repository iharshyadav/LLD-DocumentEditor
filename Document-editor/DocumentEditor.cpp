#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class DocumentEditor
{
private:
    vector<string> text;
    string renderedDocument;

public:
    void addText(string s)
    {
        text.push_back(s);
    }

    void addImage(string s)
    {
        text.push_back(s);
    }

    // Render the document by checking the type of each element at runtime
    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            string result = "";
            for (auto element : text)
            {
                if (element.size() > 4 && element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 4) == ".png")
                {
                    result += "[Image: " + element + "]" + "\n";
                }
                else
                {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document saved successfully" << endl;
        }
        else
        {
            cout << "Document not saved successfully" << endl;
        }
    }
};

int main()
{
    DocumentEditor editor;

    editor.addImage("harsh.jpg");

    editor.addText("yadav");
    cout << editor.renderDocument() << endl;

    editor.saveToFile();

    return 0;
}