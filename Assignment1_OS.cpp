
DAY=$(date+%F)
cd.
for FILE in *.png
do
  mv $FILE ${DAY}-${FILE}
done
//Commands ls---> chmod +x Filename.sh ---> touch abcd.png ---> ls ---> ./filename.sh --->ls

//2.Delete the zero-sized file:

clear
echo "Enter any File name"
read filenm

if [ -e $filenm]
then 
   echo $filenm "File Exists"
   if[ -s $filenm]
   then 
    echo $filenm "File has size >0"
    else
    rm $filenm
    echo $filenm "Zero sized File is deleted!"
    fi
else
    echo "File does not exist"
fi  
//command: first of all create empty text file then enter only file name 

//3.Take an input file and remove identical lines (or duplicate lines from the file)  
echo "Enter the any file name to remove identical lines"
read filenm
cat -n $filenm | sort -k2 | uniq -f1 | sort -k1 | cut -f2 

//Commands:First make text file of identical names then do step by step following commands
//cat -n $filenm | sort -k2 | uniq -f1 | sort -k1 | cut -f2 

//OR
echo "Enter the file name: "
read file 
sort $file | uniq > duplicate_names.txt
cat duplicate_names.txt















