# tergp
tergp, a simple template for creating terminal-based games with an explorable map using ncurses. 
You can alter the game's map via the map(n).txt file, and its attributes in the map(n)_mdat.txt file. All the info that can be written in the mdat file is in a rules.txt file in the main project folder, and you can put more data if needed in the file. To process the additional data, you will need to change the proc_list function, which processes the linked list created by the mdat file and the get_mdat_file funciton into the map Struct. 
The project still needs a bit more modularity, organization, comments and features, which im currently working on. I will also futurely publish an example of a game using this prototype.
