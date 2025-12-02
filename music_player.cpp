#include <iostream>
#include <string>
using namespace std;

struct Song {
    int id;
    string title;
    string author;
    float duration;
    Song* next;
};

Song* first = NULL;
Song* last = NULL;
Song* current = NULL;

void add_song() {
    Song* s = new Song;
    cout << "Enter Song ID: ";
    cin >> s->id;
    cout << "Enter Song Title: ";
    cin >> s->title;
    cout << "Enter Author: ";
    cin >> s->author;
    cout << "Enter Duration (in minutes): ";
    cin >> s->duration;

    if (first == NULL) {
        first = last = s;
        s->next = first;
    } else {
        last->next = s;
        last = s;
        last->next = first;
    }

    cout << "Song added successfully!\n";
}

void display_playlist() {
    if (first == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = first;
    cout << "\nPlaylist:\n";
    do {
        cout << "ID: " << temp->id
             << " | Title: " << temp->title
             << " | Author: " << temp->author
             << " | Duration: " << temp->duration << " min\n";
        temp = temp->next;
    } while (temp != first);

    cout << "\n";
}

void delete_song(int id) {
    if (first == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* curr = first;
    Song* prev = last;

    do {
        if (curr->id == id) {
            if (curr == first && curr == last) {
                first = last = NULL;
            } else {
                if (curr == first)
                    first = first->next;
                if (curr == last)
                    last = prev;
                prev->next = curr->next;
            }
            delete curr;
            cout << "Song deleted successfully!\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    } while (curr != first);

    cout << "Song not found!\n";
}

void delete_duplicate_songs() {
    if (first == NULL)
        return;

    Song* curr = first;

    do {
        Song* temp = curr;
        Song* check = curr->next;

        while (check != first) {
            if (check->id == curr->id) {
                temp->next = check->next;
                if (check == last)
                    last = temp;
                delete check;
                check = temp->next;
            } else {
                temp = check;
                check = check->next;
            }
        }

        curr = curr->next;
    } while (curr != first);

    cout << "All duplicate songs removed!\n";
}

void play_song(Song* s) {
    if (s == NULL) {
        cout << "No song to play!\n";
        return;
    }

    cout << "\nNow Playing:\n";
    cout << "Title: " << s->title << "\n";
    cout << "Author: " << s->author << "\n";
    cout << "Duration: " << s->duration << " min\n\n";
}

void start_playback() {
    if (first == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    current = first;
    play_song(current);
}

void play_next() {
    if (current == NULL) {
        cout << "No current song selected!\n";
        return;
    }

    current = current->next;
    play_song(current);
}

void play_previous() {
    if (current == NULL || current == first) {
        cout << "You are at the first song!\n";
        return;
    }

    Song* temp = first;
    while (temp->next != current)
        temp = temp->next;

    current = temp;
    play_song(current);
}

int main() {
    int choice, id;

    while (true) {
        cout << "\nComsats Music Player\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Songs\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Remove Duplicate Songs\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_song(); break;
            case 2: cout << "Enter Song ID: "; cin >> id; delete_song(id); break;
            case 3: display_playlist(); break;
            case 4: start_playback(); break;
            case 5: play_next(); break;
            case 6: play_previous(); break;
            case 7: delete_duplicate_songs(); break;
            case 8: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
