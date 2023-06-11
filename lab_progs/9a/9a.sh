if [ $# != 2 ] # checks command line inputs
    then
    echo "Invalid input!!!"
else
    p1=`ls -l $1|cut -d " " -f1` #command to get permissions
    p2=`ls -l $2|cut -d " " -f1` 
    if [ $p1 == $p2 ] # checking if the permissions are same
    then
        echo "the file permissions are same and it is : "
        echo "$p1"
    else
        echo "The file permissions are different"
        echo "$1 : $p1"
        echo "$2 : $p2"
    fi
fi
