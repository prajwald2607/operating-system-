/*Write a shell script to Simulate the two level
directory organization (read file, write file ,create file, delete file,
rename file, create directory etc)*/

i="y"
while [ $i= "y" ]
do
echo "1.List of files and directories"
echo "2.Create the Directory"
echo "3.Change the Directory"
echo "4.Delete the file"
echo "5.Change the file name"
echo "Enter your choice"
read ch
case $ch in
        1)echo "List of files and Directories are displayed!"
          ls;;
        2)echo "Enter the name of the Directory to be created!"
          read newdirname
          mkdir $newdirname;;
        3)echo "To change the directory"
		  echo "Enter the directory name"
		  read chgdirname
		  cd $chgdirname;;
		4)echo "Enter the directory name"
		  read dirname
		  rm -r $dirname;;
		5)echo "Enter the directory name to change the file name"
		  read dirname
		  echo "Enter the new name of the file"
		  read newname
		  mv $dirname $newname;;
		  *)
		  echo "Invalid choice";;
		  esac
		  echo "Do you want to continue?"
		  read i
		  if [$i!="y"]
		  then
		     exit 
		  fi  
		 done    

//Commands://Commands ls---> chmod +x Filename.sh ---> ls ---> ./filename.sh --->
		 
		  		        
          
		  
