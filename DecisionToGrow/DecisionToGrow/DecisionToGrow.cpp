#include <iostream>
#include <string>
#include <random>

using namespace std;

void attack() {
    cout << "Attacking!" << endl;
}

void defend() {
    cout << "Defending!" << endl;
}

void heal() {
    cout << "Healing!" << endl;
}

void showData(int decisions[30][7]) {
    for (int i = 0; i < 30; i++) {
        printf("%d %d %d %d %d %d\n", decisions[i][0], decisions[i][1], decisions[i][2], decisions[i][3], decisions[i][4], decisions[i][5]);
    }
}

int learn() {
    // Multiclass decision tree implementation.
    // Random forest implementation. Voting should take place to determine right
    // course of action.
    // This gon take some work. It's gon take a lot of work ngl
}

int main() {
    string situations[3] = { "Opponent attacked.", "Opponent defended.", "Opponent healed." };

    // What I want my dataset to look like:
    // user_attack, user_defend, user_heal, opp_attack, opp_defend, opp_heal, class
    // Classes attacker, defender, healer are determined by 1, 2 and 3 respectively.

    // Ex:
    // [1, 0, 0, 0, 0, 1, 1] would mean the user attacked, the opponent healed and the user
    // is identified as an attacker.
    int decisions[30][7] = { };
    int i = 0;

    // Here, we implement a random number generator to start the opponent's first action.
    // Every other subsequent action will be determined by the decisions made by the player.
    // The opponent will attempt to counter the player's actions before they even make it.
    std::random_device random;
    std::mt19937 generate(random());
    std::uniform_int_distribution<> distribution(0, 2);

    int situation = distribution(generate);
    string s = situations[situation];

    if (situation == 0) {
        cout << s << endl;
    } else if (situation == 1) {
        cout << s << endl;
    } else {
        cout << s << endl;
    }
    decisions[i][situation] = 1;
    int classification = situation + 1;

    while (true) {
        cout << "Turn: " << i + 1 << endl;
        
        cout << "Enter a command (attack, defend or heal): ";
        string x;
        cin >> x;

        if (x == "exit") {
            break;
        } else if (x == "attack" || x == "defend" || "heal") {
            switch (classification) {
                case 1:
                    // If user is classified as an attacker, we defend
                    decisions[i][4] = 1;
                    break;
                case 2:
                    // If user is classified as a defender, we heal
                    decisions[i][5] = 1;
                    break;
                case 3:
                    // If user is classified as a healer, we attack
                    decisions[i][3] = 1;
                    break;
                default:
                    break;
            }
            decisions[i][6] = learn();
            
            // User's attack, defend, heal count gets updated.
            if (x == "attack") {
                attack();
                decisions[i][0] = decisions[i][0] + 1;
            } else if (x == "defend") {
                defend();
                decisions[i][1] = decisions[i][1] + 1;
            } else {
                heal();
                decisions[i][2] = decisions[i][2] + 1;
            }
            // Opponent learns and makes a decision for the next turn.
            classification = decisions[i][6];

            showData(decisions);
            i++;
        } else {
            cout << "Invalid command. Enter again." << endl;
        }
    }
}