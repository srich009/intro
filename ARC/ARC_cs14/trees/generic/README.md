Getting the code
-----------------

To grab all the code, clone this repo locally with the following command (in your terminal)

    git clone https://github.com/scohe001/Tree.git

Exercises
---------

Once you've got it all, begin the following exercises (they can also be found in comments at the end of tree.h):

 1. Draw the postorder traversal order on paper and then write the print
      function to print the tree in postorder

 2. Draw the inorder traversal order on paper and then write the print
      function to print the tree inorder (remember for trees with children > 2
      inorder means you visit the left child, yourself, and then the rest of
      your children from left to right)

 3. Write a member function to Find the height of the tree (number of
      levels - 1 according to Miller)

 4. Write a member function to find the shortest path to a leaf (the height of
      the shortest leaf)

 5. Write an avg function to find the mean of all of the values in the tree

 5. Overload the == operator so we can check if two trees are equal. Remember
      that comparing pointers won't get you anywhere since two trees can be
      equivalent, but with their data in different places!
