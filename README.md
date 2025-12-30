# Anunnaki Keyboard
![Platform: Windows](https://img.shields.io/badge/platform-Windows-blue?logo=windows)
&nbsp;<sup>[Download](https://github.com/dnaspider/anunnaki/releases)</sup>

<pre>Quick start

Set this up first in Visual Studio Code
(Or don't. Just know when you press TAB in this editor it generates spaces instead).
  
  Click [{} plain text] on the bottom right.
  
  Click Configure 'Plain Text' language based settings...
  
  Add this to enable tab characters for .txt files instead of the default spaces.
  
  <code>"[plaintext]": {
    "editor.insertSpaces": false
  }</code>
  
  Save.

Now i'll explain how to program your keyboard to function the way you really want it to.

First thing to do is plan which two keys you'll be using for your shortcut.
I made it so each key shows its corresponding value in the program
when the key is pressed. Have a look. 
These keys are pretty much the input (to make it more or less then two keys, in c:\anu\se.txt,
adjust InputLength; CTRL+S to update the program). 

Lets start adding codes to c:\anu\db.txt.

But first, know this:

After adding codes to db.txt in Visual Studio Code,
press CTRL+S to save. When pressing CTRL+S, the
program will update itself to see the codes.

Codes in c:\anu\db.txt have this format
(with the symbol between the input and output):

in out
in-out
in:out
in>out

For multi-line use this format
(with the \ before the middle symbol and another on the end of the final line):
in\>
  out
\

Use space or - character as the middle symbol for auto backspace input
(like in the first two examples above).

Use > when you want it to output the input as well for whatever reason for repeat
(see further below which key to press for repeat).

Also know this:

The input is your shortcut. The output is what will run.

And, each line in db.txt is a slot for its own shortcut (using the multi-line format compresses it to one line by removing new lines and tabs after saving of course).

Simple emoji example:

in 💥

Can have more than one input to run the same output.
Just place only an input above where it has an input and output:
i
in 💥

However, you might have to clear the input first with this combo:
Hold RSHIFT, Press LSHIFT three times, release RSHIFT
(Pressing only twice clears it to &lt;.
Press once when its alredy cleared for &lt;
or to run if its filled with an input).

To run the out, first CTRL+S to save then press:
I N RCTRL
I N F2
or
I N RSHIFT+LSHIFT (Hold RSHIFT, press LSHIFT, release RSHIFT)

To repeat, press:
PAUSE/BREAK
or 
RCTRL+LCTRL

Lets expand.

For teleport and mouse press, click in db.txt,
hover over the target, press P+ESC.
It will auto type something like this &lt;xy~:273 1365>.
The ~ means it will store the location first
then it will teleport to x y location: 273 1365.
For left click, use &lt;lc>
(Left click more than once &lt;lc2>).

Example:
in &lt;xy~:273 1365>&lt;lc>&lt;~~>

The &lt;~~> will return the x y to where it was stored.

Maybe sometimes you might have to slow it down and put some wait time like this
(using this &lt;,> option):
  
in &lt;xy~:273 1365>&lt;,>&lt;lc>&lt;,>&lt;~~>
  
Maybe thats not enough time (160ms default).
Add more milliseconds to this like so: &lt;,1000> (this is one second).

Can also use the &lt;speed:> option instead:
in &lt;speed:160>&lt;xy~:273 1365>&lt;lc>&lt;~~>

To see what options this program has to offer, press ?+ESC.

Any questions? Hit me up on 𝕏 or Discussions.

Enjoy my friend. You are a brave soul and I appreciate you (trust)!
</pre>
