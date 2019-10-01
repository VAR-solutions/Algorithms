//iterative method

sub binary_search {
    my ($array_ref, $value, $left, $right) = @_;
    while ($left <= $right) {
        my $middle = int(($right + $left) >> 1);
        if ($value == $array_ref->[$middle]) {
            return $middle;
        }
        elsif ($value < $array_ref->[$middle]) {
            $right = $middle - 1;
        }
        else {
            $left = $middle + 1;
        }
    }
    return -1;
}
