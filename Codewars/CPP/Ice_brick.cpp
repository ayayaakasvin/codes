int ice_brick_volume(int radius, int bottle_length, int rim_length) {
    int result = (bottle_length - rim_length) * radius * radius * 2;
    return result;
}