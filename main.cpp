#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "teams/Team.h"
#include "fields/Field.h"
#include "matches/Match.h"
#include "registrations/Registration.h"
#include "referees/Referee.h"
#include "spectators/Ticket.h"
#include "results/Result.h"
#include "rankings/Ranking.h"

int main() {
    int choice;
    std::vector<Team> teams;
    std::vector<Field> fields;
    std::vector<Match> matches;
    std::vector<Registration> registrations;
    std::vector<Referee> referees;
    std::vector<Result> results;
    std::vector<Ticket> tickets;
    std::vector<Ranking> rankings;

    do {
        std::cout << "=== Football Tournament Manager ===\n";
        std::cout << "1. Manage Teams\n";
        std::cout << "2. Manage Fields\n";
        std::cout << "3. Schedule Matches\n";
        std::cout << "4. Manage Registrations\n";
        std::cout << "5. Assign Referees\n";
        std::cout << "6. Manage Tickets\n";
        std::cout << "7. Record Results\n";
        std::cout << "8. View Rankings\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                int teamChoice;
                do {
                    std::cout << "\n--- Manage Teams ---\n";
                    std::cout << "1. Add Team\n";
                    std::cout << "2. Remove Team\n";
                    std::cout << "3. View Teams\n";
                    std::cout << "0. Return to Main Menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> teamChoice;

                    if(teamChoice == 1) {
                        std::string name;
                        int ranking;
                        std::cout << "Enter team name: ";
                        std::cin.ignore(); // Clear newline from buffer
                        std::getline(std::cin, name);
                        std::cout << "Enter team ranking: ";
                        std::cin >> ranking;
                        teams.emplace_back(name, ranking);
                        // Initialize Ranking for the new team
                        rankings.emplace_back(&teams.back(), 0, 0, 0, 0, 0);
                        std::cout << "Team added successfully.\n";
                    }
                    else if(teamChoice == 2) {
                        std::string name;
                        std::cout << "Enter team name to remove: ";
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        bool found = false;
                        for(auto it = teams.begin(); it != teams.end(); ++it) {
                            if(it->getName() == name) {
                                // Remove associated Ranking
                                rankings.erase(
                                    std::remove_if(rankings.begin(), rankings.end(),
                                        [&](const Ranking& r) { return r.getTeam()->getName() == name; }),
                                    rankings.end()
                                );
                                teams.erase(it);
                                std::cout << "Team removed successfully.\n";
                                found = true;
                                break;
                            }
                        }
                        if(!found) {
                            std::cout << "Team not found.\n";
                        }
                    }
                    else if(teamChoice == 3) {
                        if(teams.empty()) {
                            std::cout << "No teams available.\n";
                        }
                        else {
                            std::cout << "\n--- Teams List ---\n";
                            for(const auto& team : teams) {
                                std::cout << "Name: " << team.getName() 
                                          << ", Ranking: " << team.getRanking() << "\n";
                            }
                        }
                    }
                    else if(teamChoice != 0) {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                } while(teamChoice != 0);
                break;
            }
            case 2: {
                int fieldChoice;
                do {
                    std::cout << "\n--- Manage Fields ---\n";
                    std::cout << "1. Add Field\n";
                    std::cout << "2. Remove Field\n";
                    std::cout << "3. View Fields\n";
                    std::cout << "0. Return to Main Menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> fieldChoice;

                    if(fieldChoice == 1) {
                        std::string name;
                        int capacity;
                        std::cout << "Enter field name: ";
                        std::cin.ignore(); // Clear newline from buffer
                        std::getline(std::cin, name);
                        std::cout << "Enter field capacity: ";
                        std::cin >> capacity;
                        fields.emplace_back(name, capacity);
                        std::cout << "Field added successfully.\n";
                    }
                    else if(fieldChoice == 2) {
                        std::string name;
                        std::cout << "Enter field name to remove: ";
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        bool found = false;
                        for(auto it = fields.begin(); it != fields.end(); ++it) {
                            if(it->getName() == name) {
                                fields.erase(it);
                                std::cout << "Field removed successfully.\n";
                                found = true;
                                break;
                            }
                        }
                        if(!found) {
                            std::cout << "Field not found.\n";
                        }
                    }
                    else if(fieldChoice == 3) {
                        if(fields.empty()) {
                            std::cout << "No fields available.\n";
                        }
                        else {
                            std::cout << "\n--- Fields List ---\n";
                            for(const auto& field : fields) {
                                std::cout << "Name: " << field.getName() 
                                          << ", Capacity: " << field.getCapacity() << "\n";
                            }
                        }
                    }
                    else if(fieldChoice != 0) {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                } while(fieldChoice != 0);
                break;
            }
            case 3: {
                if (teams.size() < 2) {
                    std::cout << "Not enough teams to schedule a match.\n";
                    break;
                }
                if (fields.empty()) {
                    std::cout << "No fields available to schedule a match.\n";
                    break;
                }

                std::cout << "\n--- Schedule Match ---\n";

                // Select Team 1
                std::cout << "Select Team 1:\n";
                for (size_t i = 0; i < teams.size(); ++i) {
                    std::cout << i + 1 << ". " << teams[i].getName() 
                              << " (Ranking: " << teams[i].getRanking() << ")\n";
                }
                int team1Index;
                std::cout << "Enter team 1 number: ";
                std::cin >> team1Index;
                if (team1Index < 1 || team1Index > teams.size()) {
                    std::cout << "Invalid team selection.\n";
                    break;
                }
                Team* team1 = &teams[team1Index - 1];

                // Select Team 2
                std::cout << "Select Team 2:\n";
                for (size_t i = 0; i < teams.size(); ++i) {
                    if ((int)(i + 1) != team1Index) { // Avoid selecting the same team
                        std::cout << i + 1 << ". " << teams[i].getName() 
                                  << " (Ranking: " << teams[i].getRanking() << ")\n";
                    }
                }
                int team2Index;
                std::cout << "Enter team 2 number: ";
                std::cin >> team2Index;
                if (team2Index < 1 || team2Index > teams.size() || team2Index == team1Index) {
                    std::cout << "Invalid team selection.\n";
                    break;
                }
                Team* team2 = &teams[team2Index - 1];

                // Select Field
                std::cout << "Select Field:\n";
                for (size_t i = 0; i < fields.size(); ++i) {
                    std::cout << i + 1 << ". " << fields[i].getName() 
                              << " (Capacity: " << fields[i].getCapacity() << ")\n";
                }
                int fieldIndex;
                std::cout << "Enter field number: ";
                std::cin >> fieldIndex;
                if (fieldIndex < 1 || fieldIndex > fields.size()) {
                    std::cout << "Invalid field selection.\n";
                    break;
                }
                Field* field = &fields[fieldIndex - 1];

                // Enter Match Phase
                std::cin.ignore(); // Clear newline from buffer
                std::string phase;
                std::cout << "Enter match phase (e.g., Group Stage, Quarter Final): ";
                std::getline(std::cin, phase);

                // Enter Scheduled Time
                std::string scheduledTime;
                std::cout << "Enter scheduled time (e.g., 2024-06-01 18:00): ";
                std::getline(std::cin, scheduledTime);

                // Create and add Match
                matches.emplace_back(phase, team1, team2, field, scheduledTime);
                std::cout << "Match scheduled successfully.\n";
                break;
            }
            case 4: {
                int regChoice;
                do {
                    std::cout << "\n--- Manage Registrations ---\n";
                    std::cout << "1. Add Registration\n";
                    std::cout << "2. Validate Registration\n";
                    std::cout << "3. View Registrations\n";
                    std::cout << "0. Return to Main Menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> regChoice;

                    if(regChoice == 1) {
                        if(teams.empty()) {
                            std::cout << "No teams available to register.\n";
                            continue;
                        }
                        std::cout << "Select Team to Register:\n";
                        for (size_t i = 0; i < teams.size(); ++i) {
                            std::cout << i + 1 << ". " << teams[i].getName() << "\n";
                        }
                        int teamIndex;
                        std::cout << "Enter team number: ";
                        std::cin >> teamIndex;
                        if (teamIndex < 1 || teamIndex > teams.size()) {
                            std::cout << "Invalid team selection.\n";
                            break;
                        }
                        Team* selectedTeam = &teams[teamIndex - 1];

                        // Check if already registered
                        bool alreadyRegistered = false;
                        for(const auto& reg : registrations) {
                            if(reg.getTeam()->getName() == selectedTeam->getName()) {
                                alreadyRegistered = true;
                                break;
                            }
                        }
                        if(alreadyRegistered) {
                            std::cout << "Team is already registered.\n";
                            break;
                        }

                        // Enter registration date
                        std::cin.ignore(); // Clear newline from buffer
                        std::string date;
                        std::cout << "Enter registration date (e.g., 2024-01-15): ";
                        std::getline(std::cin, date);

                        // Create and add Registration
                        registrations.emplace_back(selectedTeam);
                        registrations.back().setDateRegistered(date);
                        registrations.back().setValidated(false);
                        std::cout << "Registration added successfully. Awaiting validation.\n";
                    }
                    else if(regChoice == 2) {
                        if(registrations.empty()) {
                            std::cout << "No registrations to validate.\n";
                            continue;
                        }
                        std::cout << "Select Registration to Validate:\n";
                        int count = 1;
                        for(const auto& reg : registrations) {
                            std::cout << count++ << ". Team: " << reg.getTeam()->getName() 
                                      << ", Date: " << reg.getDateRegistered() 
                                      << ", Validated: " << (reg.isValidated() ? "Yes" : "No") << "\n";
                        }
                        int regIndex;
                        std::cout << "Enter registration number to validate: ";
                        std::cin >> regIndex;
                        if(regIndex < 1 || regIndex > registrations.size()) {
                            std::cout << "Invalid registration selection.\n";
                            break;
                        }
                        if(registrations[regIndex - 1].isValidated()) {
                            std::cout << "Registration already validated.\n";
                        }
                        else {
                            registrations[regIndex - 1].setValidated(true);
                            std::cout << "Registration validated successfully.\n";
                        }
                    }
                    else if(regChoice == 3) {
                        if(registrations.empty()) {
                            std::cout << "No registrations available.\n";
                        }
                        else {
                            std::cout << "\n--- Registrations List ---\n";
                            for(const auto& reg : registrations) {
                                std::cout << "Team: " << reg.getTeam()->getName() 
                                          << ", Date Registered: " << reg.getDateRegistered() 
                                          << ", Validated: " << (reg.isValidated() ? "Yes" : "No") << "\n";
                            }
                        }
                    }
                    else if(regChoice != 0) {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                } while(regChoice != 0);
                break;
            }
            case 5: {
                if (referees.empty()) {
                    std::cout << "No referees available. Please add referees first.\n";
                    break;
                }
                if (matches.empty()) {
                    std::cout << "No matches available to assign referees.\n";
                    break;
                }

                // List matches without referees
                std::vector<Match*> unassignedMatches;
                for(auto &match : matches) {
                    if(match.getReferee() == nullptr){
                        unassignedMatches.push_back(&match);
                    }
                }

                if(unassignedMatches.empty()) {
                    std::cout << "All matches have referees assigned.\n";
                    break;
                }

                std::cout << "\n--- Assign Referees ---\n";
                std::cout << "Select a match to assign a referee:\n";
                for(size_t i = 0; i < unassignedMatches.size(); ++i){
                    std::cout << i + 1 << ". " << unassignedMatches[i]->getTeam1()->getName() 
                              << " vs " << unassignedMatches[i]->getTeam2()->getName() 
                              << " on " << unassignedMatches[i]->getScheduledTime() << "\n";
                }
                int matchChoice;
                std::cout << "Enter match number: ";
                std::cin >> matchChoice;
                if(matchChoice < 1 || matchChoice > unassignedMatches.size()){
                    std::cout << "Invalid match selection.\n";
                    break;
                }
                Match* selectedMatch = unassignedMatches[matchChoice - 1];

                // List referees
                std::cout << "Select a referee to assign:\n";
                for(size_t i = 0; i < referees.size(); ++i){
                    std::cout << i + 1 << ". " << referees[i].getName() 
                              << " (" << referees[i].getCertifications() << ")\n";
                }
                int refereeChoice;
                std::cout << "Enter referee number: ";
                std::cin >> refereeChoice;
                if(refereeChoice < 1 || refereeChoice > referees.size()){
                    std::cout << "Invalid referee selection.\n";
                    break;
                }
                Referee* selectedReferee = &referees[refereeChoice - 1];

                // Assign referee to match
                selectedMatch->setReferee(selectedReferee);
                std::cout << "Referee assigned successfully.\n";
                break;
            }
            case 6: {
                int ticketChoice;
                do {
                    std::cout << "\n--- Manage Tickets ---\n";
                    std::cout << "1. Add Ticket\n";
                    std::cout << "2. Remove Ticket\n";
                    std::cout << "3. View Tickets\n";
                    std::cout << "0. Return to Main Menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> ticketChoice;

                    if(ticketChoice == 1) {
                        if(matches.empty()) {
                            std::cout << "No matches available to assign tickets.\n";
                            continue;
                        }
                        std::cout << "Select Match for the Ticket:\n";
                        for (size_t i = 0; i < matches.size(); ++i) {
                            std::cout << i + 1 << ". " << matches[i].getTeam1()->getName() 
                                      << " vs " << matches[i].getTeam2()->getName() 
                                      << " on " << matches[i].getScheduledTime() << "\n";
                        }
                        int matchIndex;
                        std::cout << "Enter match number: ";
                        std::cin >> matchIndex;
                        if(matchIndex < 1 || matchIndex > matches.size()){
                            std::cout << "Invalid match selection.\n";
                            break;
                        }
                        Match* selectedMatch = &matches[matchIndex - 1];

                        std::string seatNumber;
                        double price;
                        std::cout << "Enter seat number: ";
                        std::cin.ignore();
                        std::getline(std::cin, seatNumber);
                        std::cout << "Enter price: ";
                        std::cin >> price;

                        // Create and add Ticket
                        tickets.emplace_back(selectedMatch, seatNumber, price);
                        std::cout << "Ticket added successfully.\n";
                    }
                    else if(ticketChoice == 2) {
                        // Implement removal logic
                        std::cout << "Ticket removal not implemented yet.\n";
                    }
                    else if(ticketChoice == 3) {
                        if(tickets.empty()) {
                            std::cout << "No tickets available.\n";
                        }
                        else {
                            std::cout << "\n--- Tickets List ---\n";
                            for(const auto& ticket : tickets) {
                                std::cout << "Match: " << ticket.getMatch()->getTeam1()->getName() 
                                          << " vs " << ticket.getMatch()->getTeam2()->getName()
                                          << ", Seat: " << ticket.getSeatNumber()
                                          << ", Price: $" << ticket.getPrice()
                                          << ", Available: " << (ticket.isAvailable() ? "Yes" : "No") << "\n";
                            }
                        }
                    }
                    else if(ticketChoice != 0) {
                        std::cout << "Invalid choice. Please try again.\n";
                    }
                } while(ticketChoice != 0);
                break;
            }
            case 7: {
                if(matches.empty()) {
                    std::cout << "No matches available to record results.\n";
                    break;
                }

                // Find matches without results
                std::vector<Match*> matchesWithoutResults;
                for(auto &match : matches) {
                    bool hasResult = false;
                    for(auto &res : results) {
                        if(res.getMatch() == &match) {
                            hasResult = true;
                            break;
                        }
                    }
                    if(!hasResult) {
                        matchesWithoutResults.push_back(&match);
                    }
                }

                if(matchesWithoutResults.empty()) {
                    std::cout << "All matches have recorded results.\n";
                    break;
                }

                std::cout << "\n--- Record Results ---\n";
                std::cout << "Select a match to record the result:\n";
                for(size_t i = 0; i < matchesWithoutResults.size(); ++i){
                    std::cout << i + 1 << ". " 
                              << matchesWithoutResults[i]->getTeam1()->getName() 
                              << " vs " << matchesWithoutResults[i]->getTeam2()->getName() 
                              << " on " << matchesWithoutResults[i]->getScheduledTime() << "\n";
                }
                int matchChoice;
                std::cout << "Enter match number: ";
                std::cin >> matchChoice;
                if(matchChoice < 1 || matchChoice > matchesWithoutResults.size()){
                    std::cout << "Invalid match selection.\n";
                    break;
                }
                Match* selectedMatch = matchesWithoutResults[matchChoice - 1];

                int scoreTeam1, scoreTeam2;
                std::cout << "Enter score for " << selectedMatch->getTeam1()->getName() << ": ";
                std::cin >> scoreTeam1;
                std::cout << "Enter score for " << selectedMatch->getTeam2()->getName() << ": ";
                std::cin >> scoreTeam2;

                // Get current time for recordedAt
                std::time_t now = std::time(0);
                char buf[80];
                std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
                std::string currentTime(buf);

                // Create and add Result
                results.emplace_back(selectedMatch, scoreTeam1, scoreTeam2);
                results.back().setRecordedAt(currentTime);
                std::cout << "Result recorded successfully.\n";

                // Update Rankings
                // Find Rankings for both teams
                Ranking* ranking1 = nullptr;
                Ranking* ranking2 = nullptr;
                for(auto &rank : rankings) {
                    if(rank.getTeam()->getName() == selectedMatch->getTeam1()->getName()) {
                        ranking1 = &rank;
                    }
                    if(rank.getTeam()->getName() == selectedMatch->getTeam2()->getName()) {
                        ranking2 = &rank;
                    }
                }

                if(ranking1 == nullptr || ranking2 == nullptr) {
                    std::cout << "Rankings not found for one or both teams.\n";
                    break;
                }

                // Update games played
                ranking1->setGamesPlayed(ranking1->getGamesPlayed() + 1);
                ranking2->setGamesPlayed(ranking2->getGamesPlayed() + 1);

                if(scoreTeam1 > scoreTeam2) {
                    // Team1 wins
                    ranking1->setWins(ranking1->getWins() + 1);
                    ranking1->setPoints(ranking1->getPoints() + 3);

                    // Team2 loses
                    ranking2->setLosses(ranking2->getLosses() + 1);
                }
                else if(scoreTeam1 < scoreTeam2) {
                    // Team2 wins
                    ranking2->setWins(ranking2->getWins() + 1);
                    ranking2->setPoints(ranking2->getPoints() + 3);

                    // Team1 loses
                    ranking1->setLosses(ranking1->getLosses() + 1);
                }
                else {
                    // Draw
                    ranking1->setDraws(ranking1->getDraws() + 1);
                    ranking1->setPoints(ranking1->getPoints() + 1);

                    ranking2->setDraws(ranking2->getDraws() + 1);
                    ranking2->setPoints(ranking2->getPoints() + 1);
                }

                break;
            }
            case 8: {
                if(rankings.empty()) {
                    std::cout << "No rankings available.\n";
                    break;
                }
                // Sort rankings based on points, then goal difference (optional)
                std::sort(rankings.begin(), rankings.end(), [](const Ranking& a, const Ranking& b) {
                    if(a.getPoints() != b.getPoints())
                        return a.getPoints() > b.getPoints();
                    return a.getGamesPlayed() < b.getGamesPlayed(); // Example secondary criteria
                });

                std::cout << "\n--- Rankings ---\n";
                for(size_t i = 0; i < rankings.size(); ++i) {
                    const Ranking& rank = rankings[i];
                    std::cout << i + 1 << ". " << rank.getTeam()->getName()
                              << " - Points: " << rank.getPoints()
                              << ", Games Played: " << rank.getGamesPlayed()
                              << ", Wins: " << rank.getWins()
                              << ", Draws: " << rank.getDraws()
                              << ", Losses: " << rank.getLosses() << "\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting application.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << std::endl;
    } while(choice != 0);

    return 0;
}