PSEUDOCODE – COMSATS MUSIC PLAYER (CIRCULAR LINKED LIST)

	Add Song
Create a new song node
Input song id, title, author and duration
If playlist is empty then
    first = new node
    last = new node
    last.next = first
Else
    last.next = new node
    last = new node
    last.next = first
End if
Display "Song added successfully"

	Display Playlist
If playlist is empty then
    Display "Playlist is empty"
    Return
End if
Set temp = first
Repeat
    Display temp song details
    temp = temp.next
Until temp = first

	Start Playback
If playlist is empty then
    Display "Playlist is empty"
    Return
End if
Set current = first
Play current song

	Play Next Song
If current is NULL then
    Display "No song selected"
    Return
End if
current = current.next
Play current song

	Play Previous Song
If current is NULL or current = first then
    Display "Already at first song"
    Return
End if
Set temp = first
While temp.next is not equal to current do
    temp = temp.next
End while
current = temp
Play current song
	Delete Song
If playlist is empty then
    Display "Playlist is empty"
    Return
End if
Set current = first
Set previous = last
Repeat
    If current.song_id equals input id then
        If current is first and last then
            first = NULL
            last = NULL
        Else
            If current is first then
                first = first.next
            End if
            If current is last then
                last = previous
            End if
            previous.next = current.next
        End if
        Delete current
        Display "Song deleted successfully"
        Return
    End if
    previous = current
    current = current.next
Until current = first
Display "Song not found"

	Remove Duplicate Songs
If playlist is empty then
    Return
End if
Set current = first
Repeat
    Set temp = current
    Set check = current.next
    While check is not equal to first do
        If check.song_id equals current.song_id then
            temp.next = check.next
            Delete check
            check = temp.next
        Else
            temp = check
            check = check.next
        End if
    End while
    current = current.next
Until current = first
Display "Duplicate songs removed"
