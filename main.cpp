#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getDec(int i) {
    switch (i) {
    case 0:
        return 128;
    case 1:
        return 64;
    case 2:
        return 32;
    case 3:
        return 16;
    case 4:
        return 8;
    case 5:
        return 4;
    case 6:
        return 2;
    case 7:
        return 1;
    default:
        return 0;
    }
}

std::string uint32_to_ip(uint32_t ip)
{
    vector<string> binaryConverted;
    string finalAnswer = "";
    int total = 0;

    // Looping through 32 bits
    for (int i = 1; i <= 32; i++) {
        if (i % 8 != 0)
            finalAnswer.append(to_string(ip % 2));
        else {
            finalAnswer.append(to_string(ip % 2));
            reverse(finalAnswer.begin(), finalAnswer.end()); // reverse
            binaryConverted.push_back(finalAnswer);
            finalAnswer = "";
        }
        ip /= 2;
    }

    // Reverse stored binary
    reverse(binaryConverted.begin(), binaryConverted.end());

    // Convert from binary to decmial
    for (auto& element : binaryConverted) {
        // Loop through 8 bits at a time
        for (int i = 0; i <= 7; i++) {
            if (element[i] == '1') {
                total += getDec(i);
            }
        }
        finalAnswer += to_string(total) + ".";
        total = 0;
    }

    // Remove trailing period
    finalAnswer.erase(finalAnswer.length() - 1);
    return finalAnswer;
}

int main() {
    cout << uint32_to_ip(2154959208) << endl; // "128.114.17.104"
    cout << uint32_to_ip(0) << endl; // 0.0.0.0
    cout << uint32_to_ip(2149583361) << endl; // 128.32.10.1

    system("pause");
	return 0;
}


// Divide by 2 to get remainder and append remainder to string

// When string reaches 8 bits, reverse and append to vector and clear string

