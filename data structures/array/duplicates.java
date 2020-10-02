public static Set<Integer> findDuplicates(int[] input) {
        Set<Integer> duplicates = new HashSet<Integer>();

        for (int i = 0; i < input.length; i++) {
            for (int j = 1; j < input.length; j++) {
                if (input[i] == input[j] && i != j) {
                    // duplicate element found
                    duplicates.add(input[i]);
                    break;
                }
            }
        }

        return duplicates;
    }
