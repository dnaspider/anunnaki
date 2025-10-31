# Anunnaki Keyboard
![Platform: Windows](https://img.shields.io/badge/platform-Windows-blue?logo=windows)
&nbsp;<sup>[download](https://github.com/dnaspider/anunnaki/releases/edit/v1.0.0.1)</sup>

<pre>Quick start

Set this up first in Visual Studio Code.
  
  Click [{} plain text] on the bottom right.
  
  Click Configure 'Plain Text' language based settings...
  
  Add this to enable tab characters for .txt files instead of the default spaces.
  
  <code>"[plaintext]": {
    "editor.insertSpaces": false
  }</code>
  
  Save.

Now you can add codes to c:\anu\db.txt.
After adding codes to db.txt in Visual Studio Code,
press LCTRL+S to save. When pressing LCTRL+S, it will
update the program to see your codes.

Codes in c:\anu\db.txt look like this
(with the symbol between the input and output):

in out
in-out
in:out
in>out

Use space or - for auto backspace in.

Emoji example:

in 💥

To run the out, first LCTRL+S to save then press:
I N RCTRL
I N F2
or
I N RSHIFT+LSHIFT (Hold RSHIFT, press LSHIFT, release RSHIFT)

To repeat, press:
PAUSE/BREAK
or 
RCTRL+LCTRL

For teleport and mouse press, click in db.txt,
hover over the target, press P+ESC.
It will auto type something like this &lt;xy~:273 1365>.
The ~ means it will store the location first
then it will teleport to x y location: 273 1365.
For left click, use &lt;lc>
(Left click more than once &lt;lc2>).

Example:
in &lt;xy~:273 1365>&lt;lc>&lt;~~>

The &lt;~~> will return the x y to where it was.

Sometimes you will have to put some more wait time like this:
  
in &lt;xy~:273 1365>&lt;,>&lt;lc>&lt;~~>
  
Maybe thats not enough time (160ms default).
Add more milliseconds to this like so: &lt;,1000> (this is one second).

Any questions? Hit me up on 𝕏 or Discussions.
Enjoy!
</pre>
