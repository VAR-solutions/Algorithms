//using recursive

sub binary_search {
    my ($array_ref, $value, $left, $right) = @_;
    return -1 if ($right < $left);
    my $middle = int(($right + $left) >> 1);
    if ($value == $array_ref->[$middle]) {
        return $middle;
    }
    elsif ($value < $array_ref->[$middle]) {
        binary_search($array_ref, $value, $left, $middle - 1);
    }
    else {
        binary_search($array_ref, $value, $middle + 1, $right);
    }
}
