#include <iostream>
#include <string>

// Problem: Given two strings, 'reference' and 'query', detect if 'query' is a subseqeunce of 'reference'.
// For example: "ab" and "bd" are both subsequences of "abcd"; but "ba" is not.

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: <executable name> <reference string> <query string>" << std::endl;
        return 1;
    }

    std::string reference{argv[1]};
    std::string query{argv[2]};

    std::cout << "Input Reference String: " << reference << std::endl;
    std::cout << "Input Query String: " << query << std::endl;

    size_t j = 0;
    for(size_t i = 0; i < reference.length(); ++i )
    {
        if (j == query.length()) {
            break;
        }
        if (reference[i] == query[j]) {
            j++;
        }
    }
    std::cout << "Is the query string a subsequence of the reference string? : " << (j == query.length()? "yes":"no") << std::endl;
    return 0;
}
