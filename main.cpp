#include <iostream>
#include <unistd.h>

using namespace std;

int print_syntax();


int fastq_2_fasta_pipe();

int fastq_2_fasta_pipe() {

    string buffer;
    unsigned int count = 0;

    while (getline(cin, buffer)) {
        if (buffer.size() == 0) continue;
        if (buffer[0] != '@') {

            cerr << "Error: Input file Format Error: Line :" << count << endl;

            exit(0);
        }
        buffer[0] = '>';
        cout << "\033[1;31m" << buffer << "\033[0m" << endl;
        count++;

        getline(cin, buffer);


        cout << "\x1B[34m"<<buffer << endl;

        getline(cin, buffer);

        if ('+' != buffer[0]) {
            cerr << "Error: Input file Format Error: Line :" << count << endl;
            exit(0);
        }

        getline(cin, buffer);

    }

    return count;

}

int print_syntax() {

    cerr << "Usage: cat/zcat/bzcat *.fq | fq2fasta | or > into another program or file" << endl;
}


int main() {

    (isatty(fileno(stdin)) ? print_syntax : fastq_2_fasta_pipe)();
    return 0;

}