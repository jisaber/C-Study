date
outdir="./output/aarch64"
filename=""
outname=""

usage()
{
    echo "help"
}

gccmake()
{
    outfile=$outdir/$outname
    echo "source: $filename "
    echo "result: $outfile"
    g++ -o $outfile $filename
    echo "=================== below is bin result ==================="
    ./$outfile
}

while getopts "f:o:h" opt;do
    case $opt in
        f)
            filename=$OPTARG;;
        o)
            outname=$OPTARG;;
        h) usage;;
    esac
done

gccmake