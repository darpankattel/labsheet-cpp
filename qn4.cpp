// Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.

#include <iostream>
#include <fstream>
using namespace std;

class MangoDB{
    private:
        string filename;
        fstream file;
    public:
        MangoDB(string filename = "")
        {
            this->filename = filename;
        }
        class Exception{
            public:
                class FileNameInvalidException{
                    public:
                        string message = "MangoDB Exception: File name is invalid. ERROR CODE: 001";
                };
                class FileOpenException{
                    public:
                        string message = "MangoDB Exception: File open failed. ERROR CODE: 010";
                };
                class FileCloseException{
                    public:
                        string message = "MangoDB Exception: File close failed. ERROR CODE: 011";
                };
                class FileReadException{
                    public:
                        string message = "MangoDB Exception: File read failed. ERROR CODE: 100";
                };
                class FileWriteException{
                    public:
                        string message = "MangoDB Exception: File write failed. ERROR CODE: 101";
                };
        };
        void connect(string fname = "" )
        {
            if (fname == "")
            {
                fname = filename;
            }
            if (fname.length() == 0)
            {
                throw Exception::FileNameInvalidException();
            }
            file.open(fname, ios::in | ios::out | ios::binary);
            if (!file)
            {
                file.open(fname, ios::out | ios::binary);
                if (!file)
                {
                    throw Exception::FileOpenException();
                }
                file.close();
                file.open(fname, ios::in | ios::out | ios::binary);
            }
        }
        void disconnect()
        {
            try
            {
                file.close();
            }
            catch (...)
            {
                throw Exception::FileCloseException();
            }
        }
        void insert(string data)
        {
            try
            {
                file << data << endl;
            }
            catch (...)
            {
                throw Exception::FileWriteException();
            }
        }
        void display()
        {
            try
            {
                char data[100];
                file.seekg(0, ios::beg);
                while (file.getline(reinterpret_cast<char*>(data), 100))
                {
                    cout << data << endl;
                }
                if (!file.eof())
                {
                    throw Exception::FileReadException();
                }
            }
            catch (...)
            {
                throw Exception::FileReadException();
            }
        }
};

int main ()
{
    MangoDB dbClient("mangodb.txt");
    try
    {
        dbClient.connect();
        dbClient.insert("Mango");
        dbClient.insert("Orange");
        dbClient.display();
        dbClient.disconnect();
    }
    catch (MangoDB::Exception::FileNameInvalidException e)
    {
        throw;
    }
    catch (MangoDB::Exception::FileOpenException e)
    {
        cout << e.message << endl;
    }
    catch (MangoDB::Exception::FileCloseException e)
    {
        cout << e.message << endl;
    }
    catch (MangoDB::Exception::FileReadException e)
    {
        cout << e.message << endl;
    }
    catch (MangoDB::Exception::FileWriteException e)
    {
        cout << e.message << endl;
    }
    catch (...)
    {
        cout << "Unknown exception" << endl;
    }
    return 0;
}