# Technology

We use Mahi-GUI for the GUI toolkit, and capnproto for the file format. 
Our undo stack is maintained by applying diffs to that capnproto data structure,
as opposed to the more traditional command stack system. This also lets us treat our
undo stack as more of a tree.

# Glossary

 * Property

 Parts have properties. These are named variables that you're meant to be able to
 change easily. Most properties will be calculated automatically based on the other
 properties, but if it can't do that your part isn't fully constrained

 * Fully constrained

 Means that an object can calculate a value for all of it's properties. If a part isn't
 fully constained it will show you what properties you can fill in in order to fully
 constrain your part.