func isOneBitCharacter(bits []int) bool {
    i := 0
    for i = 0; i<len(bits); {
        if i == len(bits) -1 && bits[i] == 0 {
            return true;
        } else if (bits[i] == 1) {
            i += 2
        } else {
            i += 1
        }
    }
    return false
}
