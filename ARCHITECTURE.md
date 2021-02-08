We use Mahi-GUI for the GUI toolkit, and capnproto for the file format. 
Our undo stack is maintained by applying diffs to that capnproto data structure,
as opposed to the more traditional command stack system. This also lets us treat our
undo stack as more of a tree.