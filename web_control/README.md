# Web Control

To run this, navigate in a anaconda prompt to the folder where this repository is stored and then type

```
python set_switch_loop.py
```
And it will loop forever, fetching the JSON file control_data.txt, extracting the switch state, and then sending the command down the serial port to set the switch to that state.  The switch Arduino code is always listening for such commands. 

The Javascript in index.html calls the PHP save-file.php and load-file.php to load the current switch state when the page loads and save the state every time a button is pressed. Buttons are [TD elements](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/td) in an [HTML table](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/table). 



## HTML AND TEXT FILES:

  - [README.md](README.md)
  - [branch.html](branch.html)
  - [control_data.txt](control_data.txt)
  - [delete-html.html](delete-html.html)
  - [delete-php.html](delete-php.html)
  - [dna.txt](dna.txt)
  - [edit-html.html](edit-html.html)
  - [edit-index.html](edit-index.html)
  - [edit-php.html](edit-php.html)
  - [index.html](index.html)
  - [readme.html](readme.html)
  - [set_switch_loop.py](set_switch_loop.py)

## PHP CODE AS RAW TEXT:

  - [php/branch.txt](php/branch.txt)
  - [php/compile-php.txt](php/compile-php.txt)
  - [php/delete-branch.txt](php/delete-branch.txt)
  - [php/delete-file.txt](php/delete-file.txt)
  - [php/generate-dna.txt](php/generate-dna.txt)
  - [php/list-branches.txt](php/list-branches.txt)
  - [php/list-files.txt](php/list-files.txt)
  - [php/load-file.txt](php/load-file.txt)
  - [php/local-replicator.txt](php/local-replicator.txt)
  - [php/replicator.txt](php/replicator.txt)
  - [php/save-file.txt](php/save-file.txt)
    
