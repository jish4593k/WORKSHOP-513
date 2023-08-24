# blockchainvoting
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
