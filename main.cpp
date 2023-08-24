#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <exception>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct Voter {
  string id;
  int age;
};

struct Candidate {
  string name;
  int number;
};

vector<Voter> voters;
vector<Candidate> candidates;

void readVotersFromFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filename);
  }

  string line;
  while (getline(file, line)) {
    vector<string> tokens = split(line, ",");
    if (tokens.size() != 2) {
      throw std::runtime_error("Invalid voter record: " + line);
    }

    Voter voter;
    voter.id = tokens[0];
    voter.age = stoi(tokens[1]);
    voters.push_back(voter);
  }
}

void readCandidatesFromFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filename);
  }

  string line;
  while (getline(file, line)) {
    vector<string> tokens = split(line, ",");
    if (tokens.size() != 2) {
      throw std::runtime_error("Invalid candidate record: " + line);
    }

    Candidate candidate;
    candidate.name = tokens[0];
    candidate.number = stoi(tokens[1]);
    candidates.push_back(candidate);
  }
}

bool isVoterEligible(const Voter& voter) {
  return voter.age >= 18 && voter.age <= 70;
}

bool isCandidateValid(const Candidate& candidate) {
  return candidate.number >= 1 && candidate.number <= 6;
}

void scanVoterId() {
  // This function uses the camera of the device to scan the voter ID.
  // The scanned ID is then stored in a temporary variable.
  Mat image;
  VideoCapture cap(0);
  if (!cap.isOpened()) {
    throw std::runtime_error("Failed to open camera");
  }

  while (true) {
    cap >> image;

    // Display the image on the screen.
    imshow("Scan Voter ID", image);

    // Wait for a key press.
    int key = waitKey(1);

    // If the 'q' key is pressed, break out of the loop.
    if (key == 'q') {
      break;
    }
  }

  // Close the camera.
  cap.release();

  // Get the scanned ID from the image.
  string voterId = getVoterIdFromImage(image);
}

bool compareVoterId(const string& voterId, const vector<Voter>& voters) {
  // This function compares the voter ID with the IDs in the CSV file.
  // If the voter ID is found, the function returns true.
  for (const Voter& voter : voters) {
    if (voter.id == voterId) {
      return true;
    }
  }
  return false;
}

void showCandidates() {
  // This function shows the names of the candidates on the screen.
  for (const Candidate& candidate : candidates) {
    cout << candidate.name << endl;
  }
}
void vote(const int& candidateNumber) {
  // This function lets the voter vote for a candidate by entering their number.
  // The vote is then recorded in a blockchain.
  if (!isCandidateValid(candidates[candidateNumber - 1])) {
    cerr << "Invalid candidate number." << endl;
    return;
  }

  // Record the vote in the blockchain.
  // Get the voter's ID.
  string voterId = scanVoterId();

  // Get the candidate's name.
  string candidateName = candidates[candidateNumber - 1].name;

  // Record the vote in the blockchain.
  // Create a new transaction.
  Transaction transaction;
  transaction.set_voter_id(voterId);
  transaction.set_candidate_name(candidateName);

  // Sign the transaction.
  transaction.sign();

  // Broadcast the transaction to the network.
  blockchain.broadcast_transaction(transaction);
}
int main() {
  // Read the voters and candidates from the CSV files.
  readVotersFromFile("voters.csv");
  readCandidatesFromFile("candidates.csv");

  // Show the names of the candidates to the voter.
  showCandidates();

  // Let the voter vote for a candidate.
  int candidateNumber;
  cout << "Enter the number of the candidate you want to vote for: ";
  cin >> candidateNumber;
  vote(candidateNumber);

  // Exit the program.
  return 0;
}

