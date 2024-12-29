#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "teams/Team.h"
#include "fields/Field.h"
#include "matches/Match.h"
#include "referees/Referee.h"
#include "spectators/Ticket.h"
#include "results/Result.h"
#include "registrations/Registration.h"
#include "seats/Seat.h"

const double VIP_PRICE = 100.0;
const double REGULAR_PRICE = 50.0;

using namespace std;

void manageTeams();
void manageFields();
void scheduleMatches();
void manageRegistrations();
void manageReferees();
void manageSpectators();
void recordResults();
void displayRankings();
Team* searchTeamByName(const string& name);
Field* searchFieldByName(const string& name);
Referee* searchRefereeByName(const string& name);


vector<Team> teams;
vector<Field> fields;
vector<Match> matches;
vector<Referee> referees;
vector<Registration> registrations;
vector<Result> results;
vector<Ticket> tickets;

int main() {
    srand(time(0)); 
    int choice;
    do {
        cout << "=== Gestionnaire de Tournoi de Football ===\n";
        cout << "1. Gestion des Équipes\n";
        cout << "2. Gestion des Terrains\n";
        cout << "3. Planification des Matchs\n";
        cout << "4. Inscriptions\n";
        cout << "5. Gestion des Arbitres\n";
        cout << "6. Gestion des Spectateurs\n";
        cout << "7. Enregistrement des Résultats\n";
        cout << "8. Classement des Équipes\n";
        cout << "0. Quitter\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                manageTeams();
                break;
            case 2:
                manageFields();
                break;
            case 3:
                scheduleMatches();
                break;
            case 4:
                manageRegistrations();
                break;
            case 5:
                manageReferees();
                break;
            case 6:
                manageSpectators();
                break;
            case 7:
                recordResults();
                break;
            case 8:
                displayRankings();
                break;
            case 0:
                cout << "Fermeture de l'application.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
        cout << endl;
    } while(choice != 0);

    return 0;
}

void manageTeams() {
    int choice;
    do {
        cout << "\n--- Gestion des Équipes ---\n";
        cout << "1. Ajouter une Équipe\n";
        cout << "2. Supprimer une Équipe\n";
        cout << "3. Consulter les Équipes\n";
        cout << "4. Rechercher une Équipe\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Team newTeam;
            newTeam.inputTeam();
            teams.push_back(newTeam);
            cout << "Équipe ajoutée avec succès.\n";
        }
        else if(choice == 2) {
            string name;
            cout << "Entrez le nom de l'équipe à supprimer: ";
            getline(cin, name);
            auto it = find_if(teams.begin(), teams.end(), [&](const Team& t) { return t.getName() == name; });
            if(it != teams.end()) {
                
                registrations.erase(remove_if(registrations.begin(), registrations.end(),
                    [&](const Registration& r) { return r.getTeam()->getName() == name; }), registrations.end());
                teams.erase(it);
                cout << "Équipe supprimée avec succès.\n";
            }
            else {
                cout << "Équipe non trouvée.\n";
            }
        }
        else if(choice == 3) {
            if(teams.empty()) {
                cout << "Aucune équipe disponible.\n";
            }
            else {
                cout << "\n--- Liste des Équipes ---\n";
                for(const auto& team : teams) {
                    team.displayTeam();
                    cout << "-------------------------\n";
                }
            }
        }
        else if(choice == 4) {
            string criteria;
            cout << "Entrez le nom de l'équipe à rechercher: ";
            getline(cin, criteria);
            Team* team = searchTeamByName(criteria);
            if(team) {
                team->displayTeam();
            }
            else {
                cout << "Équipe non trouvée.\n";
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void manageFields() {
    int choice;
    do {
        cout << "\n--- Gestion des Terrains ---\n";
        cout << "1. Ajouter un Terrain\n";
        cout << "2. Supprimer un Terrain\n";
        cout << "3. Consulter les Terrains\n";
        cout << "4. Rechercher un Terrain\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            string name;
            int capacity;
            cout << "Entrez le nom du terrain: ";
            getline(cin, name);
            cout << "Entrez la capacité du terrain: ";
            cin >> capacity;
            cin.ignore();
            Field newField(name, capacity);
            
            for(int i = 1; i <= capacity; ++i) {
                newField.getSeats().emplace_back(i);
            }
            fields.push_back(newField);
            cout << "Terrain ajouté avec succès.\n";
        }
        else if(choice == 2) {
            string name;
            cout << "Entrez le nom du terrain à supprimer: ";
            getline(cin, name);
            auto it = find_if(fields.begin(), fields.end(), [&](const Field& f) { return f.getName() == name; });
            if(it != fields.end()) {
                
                matches.erase(remove_if(matches.begin(), matches.end(),
                    [&](const Match& m) { return m.getField() && m.getField()->getName() == name; }), matches.end());
                fields.erase(it);
                cout << "Terrain supprimé avec succès.\n";
            }
            else {
                cout << "Terrain non trouvé.\n";
            }
        }
        else if(choice == 3) {
            if(fields.empty()) {
                cout << "Aucun terrain disponible.\n";
            }
            else {
                cout << "\n--- Liste des Terrains ---\n";
                for(const auto& field : fields) {
                    field.displayField();
                    cout << "-------------------------\n";
                }
            }
        }
        else if(choice == 4) {
            string criteria;
            cout << "Entrez le nom du terrain à rechercher: ";
            getline(cin, criteria);
            Field* field = searchFieldByName(criteria);
            if(field) {
                field->displayField();
            }
            else {
                cout << "Terrain non trouvé.\n";
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void scheduleMatches() {
    int choice;
    do {
        cout << "\n--- Planification des Matchs ---\n";
        cout << "1. Créer des Matchs\n";
        cout << "2. Afficher les Matchs\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            if(teams.size() < 2) {
                cout << "Pas assez d'équipes pour planifier des matchs.\n";
                continue;
            }
            if(fields.empty()) {
                cout << "Aucun terrain disponible pour planifier des matchs.\n";
                continue;
            }
            
            vector<MatchPhase> phases = {MatchPhase::GroupStage, MatchPhase::QuarterFinal, MatchPhase::SemiFinal, MatchPhase::Final};
            for(auto phase : phases) {
                
                for(int i = 0; i < 2; ++i) {
                    
                    int team1Index = rand() % teams.size();
                    int team2Index = rand() % teams.size();
                    while(team2Index == team1Index) {
                        team2Index = rand() % teams.size();
                    }
                    Team* team1 = &teams[team1Index];
                    Team* team2 = &teams[team2Index];

                    // Assign a random field
                    int fieldIndex = rand() % fields.size();
                    Field* field = &fields[fieldIndex];

                    // Scheduled time can be set as a placeholder
                    string scheduledTime = "2024-07-01 18:00";

                    Match newMatch(team1, team2, scheduledTime);
                    newMatch.setPhase(phase);
                    newMatch.setField(field);
                    matches.push_back(newMatch);
                }
            }
            cout << "Matchs créés avec succès.\n";
        }
        else if(choice == 2) {
            if(matches.empty()) {
                cout << "Aucun match planifié.\n";
            }
            else {
                cout << "\n--- Liste des Matchs ---\n";
                for(const auto& match : matches) {
                    cout << match.displayMatch() << endl;
                }
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void manageRegistrations() {
    int choice;
    do {
        cout << "\n--- Inscriptions ---\n";
        cout << "1. Inscrire une Équipe\n";
        cout << "2. Valider une Inscription\n";
        cout << "3. Annuler une Inscription\n";
        cout << "4. Afficher les Inscriptions\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            if(teams.empty()) {
                cout << "Aucune équipe disponible à inscrire.\n";
                continue;
            }
            cout << "Sélectionnez une équipe à inscrire:\n";
            for(size_t i = 0; i < teams.size(); ++i) {
                cout << i + 1 << ". " << teams[i].getName() << endl;
            }
            int teamIndex;
            cout << "Entrez le numéro de l'équipe: ";
            cin >> teamIndex;
            cin.ignore();
            if(teamIndex < 1 || teamIndex > teams.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            Team* selectedTeam = &teams[teamIndex - 1];
            
            bool alreadyRegistered = false;
            for(const auto& reg : registrations) {
                if(reg.getTeam()->getName() == selectedTeam->getName()) {
                    alreadyRegistered = true;
                    break;
                }
            }
            if(alreadyRegistered) {
                cout << "Équipe déjà inscrite.\n";
                continue;
            }
            Registration newReg(selectedTeam);
            newReg.inputRegistration();
            registrations.push_back(newReg);
            cout << "Inscription ajoutée avec succès. En attente de validation.\n";
        }
        else if(choice == 2) {
            if(registrations.empty()) {
                cout << "Aucune inscription à valider.\n";
                continue;
            }
            cout << "Sélectionnez une inscription à valider:\n";
            for(size_t i = 0; i < registrations.size(); ++i) {
                cout << i + 1 << ". Équipe: " << registrations[i].getTeam()->getName()
                     << ", Date: " << registrations[i].getDateRegistered()
                     << ", Validée: " << (registrations[i].isValidated() ? "Oui" : "Non") << endl;
            }
            int regIndex;
            cout << "Entrez le numéro de l'inscription: ";
            cin >> regIndex;
            cin.ignore();
            if(regIndex < 1 || regIndex > registrations.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            if(registrations[regIndex - 1].isValidated()) {
                cout << "Inscription déjà validée.\n";
            }
            else {
                registrations[regIndex - 1].Validate();
                cout << "Inscription validée avec succès.\n";
            }
        }
        else if(choice == 3) {
            if(registrations.empty()) {
                cout << "Aucune inscription à annuler.\n";
                continue;
            }
            cout << "Sélectionnez une inscription à annuler:\n";
            for(size_t i = 0; i < registrations.size(); ++i) {
                cout << i + 1 << ". Équipe: " << registrations[i].getTeam()->getName()
                     << ", Date: " << registrations[i].getDateRegistered()
                     << ", Validée: " << (registrations[i].isValidated() ? "Oui" : "Non") << endl;
            }
            int regIndex;
            cout << "Entrez le numéro de l'inscription: ";
            cin >> regIndex;
            cin.ignore();
            if(regIndex < 1 || regIndex > registrations.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            if(!registrations[regIndex - 1].isValidated()) {
                cout << "Inscription déjà annulée.\n";
            }
            else {
                registrations[regIndex - 1].inValidate();
                cout << "Inscription annulée avec succès.\n";
            }
        }
        else if(choice == 4) {
            if(registrations.empty()) {
                cout << "Aucune inscription disponible.\n";
            }
            else {
                cout << "\n--- Liste des Inscriptions ---\n";
                for(const auto& reg : registrations) {
                    cout << "Équipe: " << reg.getTeam()->getName()
                         << ", Date Inscription: " << reg.getDateRegistered()
                         << ", Validée: " << (reg.isValidated() ? "Oui" : "Non") << endl;
                }
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void manageReferees() {
    int choice;
    do {
        cout << "\n--- Gestion des Arbitres ---\n";
        cout << "1. Ajouter un Arbitre\n";
        cout << "2. Supprimer un Arbitre\n";
        cout << "3. Consulter les Arbitres\n";
        cout << "4. Assignation d'Arbitre à un Match\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            Referee newRef("", "");
            newRef.inputReferee();
            referees.push_back(newRef);
            cout << "Arbitre ajouté avec succès.\n";
        }
        else if(choice == 2) {
            string name;
            cout << "Entrez le nom de l'arbitre à supprimer: ";
            getline(cin, name);
            auto it = find_if(referees.begin(), referees.end(), [&](const Referee& r) { return r.getName() == name; });
            if(it != referees.end()) {
                
                for(auto &match : matches) {
                    if(match.getReferee() && match.getReferee()->getName() == name) {
                        match.setReferee(nullptr);
                    }
                }
                referees.erase(it);
                cout << "Arbitre supprimé avec succès.\n";
            }
            else {
                cout << "Arbitre non trouvé.\n";
            }
        }
        else if(choice == 3) {
            if(referees.empty()) {
                cout << "Aucun arbitre disponible.\n";
            }
            else {
                cout << "\n--- Liste des Arbitres ---\n";
                for(const auto& ref : referees) {
                    ref.displayReferee();
                    cout << "-------------------------\n";
                }
            }
        }
        else if(choice == 4) {
            if(matches.empty()) {
                cout << "Aucun match disponible.\n";
                continue;
            }
            if(referees.empty()) {
                cout << "Aucun arbitre disponible.\n";
                continue;
            }
            cout << "Sélectionnez un match:\n";
            for(size_t i = 0; i < matches.size(); ++i) {
                cout << i + 1 << ". " << matches[i].displayMatch() << endl;
            }
            int matchIndex;
            cout << "Entrez le numéro du match: ";
            cin >> matchIndex;
            cin.ignore();
            if(matchIndex < 1 || matchIndex > matches.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            Match* selectedMatch = &matches[matchIndex - 1];
            if(selectedMatch->getReferee() != nullptr) {
                cout << "Un arbitre est déjà assigné à ce match.\n";
                continue;
            }
            cout << "Sélectionnez un arbitre à assigner:\n";
            for(size_t i = 0; i < referees.size(); ++i) {
                cout << i + 1 << ". " << referees[i].getName() << " (" << referees[i].getCertifications() << ")" << endl;
            }
            int refIndex;
            cout << "Entrez le numéro de l'arbitre: ";
            cin >> refIndex;
            cin.ignore();
            if(refIndex < 1 || refIndex > referees.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            Referee* selectedRef = &referees[refIndex - 1];
            selectedMatch->setReferee(selectedRef);
            cout << "Arbitre assigné avec succès.\n";
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void manageSpectators() {
    int choice;
    do {
        cout << "\n--- Gestion des Spectateurs ---\n";
        cout << "1. Acheter un Billet\n";
        cout << "2. Supprimer un Billet\n";
        cout << "3. Consulter les Billets\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            if(matches.empty()) {
                cout << "Aucun match disponible.\n";
                continue;
            }
            cout << "Sélectionnez un match pour acheter un billet:\n";
            for(size_t i = 0; i < matches.size(); ++i) {
                cout << i + 1 << ". " << matches[i].displayMatch() << endl;
            }
            int matchIndex;
            cout << "Entrez le numéro du match: ";
            cin >> matchIndex;
            cin.ignore();
            if(matchIndex < 1 || matchIndex > matches.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            Match* selectedMatch = &matches[matchIndex - 1];
            
            
            Field* field = selectedMatch->getField();
            if(!field) {
                cout << "Aucun terrain assigné à ce match.\n";
                continue;
            }
            if(field->getCapacity() == 0) {
                cout << "Capacité du terrain non définie.\n";
                continue;
            }

            cout << "Sélectionnez un siège:\n";
            for(const auto& seat : field->getSeats()) {
                if(seat.isEmpty()) {
                    cout << seat.getNum() << " - " << (seat.getType() == SeatType::VIP ? "VIP" : "Regular") << endl;
                }
            }
            int seatNumber;
            cout << "Entrez le numéro du siège: ";
            cin >> seatNumber;
            cin.ignore();
            
            bool available = false;
            Seat* selectedSeat = nullptr;
            for(auto& seat : field->getSeats()) {
                if(seat.getNum() == seatNumber && seat.isEmpty()) {
                    available = true;
                    selectedSeat = &seat;
                    break;
                }
            }
            if(!available) {
                cout << "Siège non disponible.\n";
                continue;
            }

            
            double price = (selectedSeat->getType() == SeatType::VIP) ? VIP_PRICE : REGULAR_PRICE;

            
            int ticketId = tickets.size() + 1;
            Ticket newTicket(ticketId, selectedMatch, selectedSeat, price);
            tickets.push_back(newTicket);
            
            selectedSeat->setEmpty(false);
            cout << "Billet acheté avec succès. Prix: $" << price << "\n";
        }
        else if(choice == 2) {
            if(tickets.empty()) {
                cout << "Aucun billet à supprimer.\n";
                continue;
            }
            cout << "Sélectionnez un billet à supprimer:\n";
            for(size_t i = 0; i < tickets.size(); ++i) {
                cout << i + 1 << ". ";
                tickets[i].displayTicket();
            }
            int ticketIndex;
            cout << "Entrez le numéro du billet: ";
            cin >> ticketIndex;
            cin.ignore();
            if(ticketIndex < 1 || ticketIndex > tickets.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            
            Seat* seat = tickets[ticketIndex - 1].getSeat();
            if(seat) {
                seat->setEmpty(true);
            }
            tickets.erase(tickets.begin() + ticketIndex - 1);
            cout << "Billet supprimé avec succès.\n";
        }
        else if(choice == 3) {
            if(tickets.empty()) {
                cout << "Aucun billet disponible.\n";
            }
            else {
                cout << "\n--- Liste des Billets ---\n";
                for(const auto& ticket : tickets) {
                    ticket.displayTicket();
                    cout << "-------------------------\n";
                }
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void recordResults() {
    if(matches.empty()) {
        cout << "Aucun match disponible.\n";
        return;
    }
    int choice;
    do {
        cout << "\n--- Enregistrement des Résultats ---\n";
        cout << "1. Enregistrer le Résultat d'un Match\n";
        cout << "2. Afficher les Résultats\n";
        cout << "0. Retour au Menu Principal\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            
            vector<Match*> matchesWithoutResults;
            for(auto &match : matches) {
                bool hasResult = false;
                for(auto &res : results) {
                    if(res.getMatch() == &match) {
                        hasResult = true;
                        break;
                    }
                }
                if(!hasResult && match.isPlayed()) {
                    matchesWithoutResults.push_back(&match);
                }
            }

            if(matchesWithoutResults.empty()) {
                cout << "Tous les matchs ont des résultats enregistrés ou n'ont pas encore été joués.\n";
                continue;
            }

            cout << "Sélectionnez un match pour enregistrer le résultat:\n";
            for(size_t i = 0; i < matchesWithoutResults.size(); ++i) {
                cout << i + 1 << ". " << matchesWithoutResults[i]->displayMatch() << endl;
            }
            int matchIndex;
            cout << "Entrez le numéro du match: ";
            cin >> matchIndex;
            cin.ignore();
            if(matchIndex < 1 || matchIndex > matchesWithoutResults.size()) {
                cout << "Sélection invalide.\n";
                continue;
            }
            Match* selectedMatch = matchesWithoutResults[matchIndex - 1];
            int score1, score2;
            cout << "Entrez le score de " << selectedMatch->getTeam1()->getName() << ": ";
            cin >> score1;
            cout << "Entrez le score de " << selectedMatch->getTeam2()->getName() << ": ";
            cin >> score2;
            cin.ignore();

            Result newResult(selectedMatch, score1, score2);
            newResult.AfterMatchCalculations();
            results.push_back(newResult);
            cout << "Résultat enregistré avec succès.\n";
        }
        else if(choice == 2) {
            if(results.empty()) {
                cout << "Aucun résultat disponible.\n";
            }
            else {
                cout << "\n--- Liste des Résultats ---\n";
                for(const auto& res : results) {
                    cout << res.getMatch()->displayMatch() << "\n"
                         << "Score: " << res.getScoreTeam1() << " - " << res.getScoreTeam2() << "\n"
                         << "-------------------------\n";
                }
            }
        }
        else if(choice != 0) {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while(choice != 0);
}

void displayRankings() {
    if(teams.empty()) {
        cout << "Aucune équipe disponible pour le classement.\n";
        return;
    }
    
    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
        if(a.calculatePoints() != b.calculatePoints())
            return a.calculatePoints() > b.calculatePoints();
        
        return false;
    });

    cout << "\n--- Classement des Équipes ---\n";
    for(size_t i = 0; i < teams.size(); ++i) {
        const Team& team = teams[i];
        cout << i + 1 << ". " << team.getName()
             << " - Points: " << team.calculatePoints()
             << ", Jeux Joués: " << team.getGamesPlayed()
             << ", Victoires: " << team.getWins()
             << ", Nuls: " << team.getDraws()
             << ", Défaites: " << team.getLosses() << endl;
    }
}

Team* searchTeamByName(const string& name) {
    for(auto &team : teams) {
        if(team.getName() == name) {
            return &team;
        }
    }
    return nullptr;
}

Field* searchFieldByName(const string& name) {
    for(auto &field : fields) {
        if(field.getName() == name) {
            return &field;
        }
    }
    return nullptr;
}

Referee* searchRefereeByName(const string& name) {
    for(auto &ref : referees) {
        if(ref.getName() == name) {
            return &ref;
        }
    }
    return nullptr;
}