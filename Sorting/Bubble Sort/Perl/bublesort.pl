# Sorts an array in place
sub bubble_sort {
    for my $i (0 .. $#_){
        for my $j ($i + 1 .. $#_){
            $_[$j] < $_[$i] and @_[$i, $j] = @_[$j, $i];
        }
    }
}
