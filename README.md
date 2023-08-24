
# INSTALLATION 
Install the C++ compiler. On Linux, you can do this by typing the following command in the terminal:
sudo apt install g++
Clone the repository containing the program code. You can do this by typing the following command in the terminal:
git clone https://github.com/bardcodes/blockchain-voting.git
Change directory to the cloned repository.
cd blockchain-voting
Compile the program.
g++ blockchain_voting.cpp -o blockchain_voting
Run the program.
./blockchain_voting
The program will then prompt the user to scan their voter ID. If the voter ID is valid, the program will show the list of candidates. The user can then vote for a candidate by entering their number. The vote will then be recorded in the blockchain.

Here are some additional notes:

The voters.csv and candidates.csv files must be located in the same directory as the blockchain_voting program.
You can change the number of candidates by editing the candidates.csv file.
You can also add more features to the program, such as the ability to verify the voter's identity and the ability to cast a vote for multiple candidates
 # EXPLANATION 
 Theis program is a simple blockchain voting system. It allows voters to vote for a candidate by entering their number. The vote is then recorded in a blockchain, which is a secure and tamper-proof way of storing data.

The program first reads the voters and candidates from CSV files. Then, it shows the names of the candidates to the voter. The voter then enters the number of the candidate they want to vote for. The program then verifies that the candidate number is valid and records the vote in the blockchain.

The program uses the following techniques to ensure the security of the voting system:

The voters and candidates are stored in CSV files, which are a common way of storing data. This makes it easy to verify the identities of the voters and candidates.
The votes are recorded in a blockchain, which is a secure and tamper-proof way of storing data. This ensures that the votes cannot be changed or deleted.
The votes are signed by the voters, which ensures that they cannot be forged.
This program is a simple example of how blockchain can be used to create a secure and transparent voting system.

Here are some additional details about the program:

The function readVotersFromFile() reads the voters from the voters.csv file. The file is a comma-separated values (CSV) file, which is a common way of storing data. Each line in the file contains the voter's ID and age.
The function readCandidatesFromFile() reads the candidates from the candidates.csv file. The file is also a CSV file, and each line contains the candidate's name and number.
The function isVoterEligible() checks if the voter is eligible to vote. A voter is eligible to vote if they are at least 18 years old and not older than 70 years old.
The function isCandidateValid() checks if the candidate is valid. A candidate is valid if their number is between 1 and 6.
The function scanVoterId() uses the camera of the device to scan the voter ID. The scanned ID is then stored in a temporary variable.
The function compareVoterId() compares the voter ID with the IDs in the CSV file. If the voter ID is found, the function returns true.
The function showCandidates() shows the names of the candidates on the screen.
The function vote() lets the voter vote for a candidate by entering their number. The vote is then recorded in a blockchain.
