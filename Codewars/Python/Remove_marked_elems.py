class List:
    def remove_(self, integer_list, values_list):
        for i in values_list:
            for _ in range(integer_list.count(i)):
                integer_list.remove(i)
        return integer_list