project(LeetCode)

set(SOURCE_FILES
        1.Two_Sum/code.cpp 1.Two_Sum/code.h
        2.Add_Two_Numbers/code.cpp 2.Add_Two_Numbers/code.h
        3.Longest_Substring_Without_Repeating_Characters/code.cpp 3.Longest_Substring_Without_Repeating_Characters/code.h
        4.Median_of_Two_Sorted_Arrays/code.cpp 4.Median_of_Two_Sorted_Arrays/code.h
        5.Longest_Palindromic_Substring/code.cpp 5.Longest_Palindromic_Substring/code.h
        6.ZigZag_Conversion/code.cpp 6.ZigZag_Conversion/code.h
        7.Reverse_Integer/code.cpp 7.Reverse_Integer/code.h
        8.String_to_Integer_atoi/code.cpp 8.String_to_Integer_atoi/code.h
        9.Palindrome_Number/code.cpp 9.Palindrome_Number/code.h
        10.Regular_Expression_Matching/code.cpp 10.Regular_Expression_Matching/code.h
        11.Container_With_Most_Water/code.cpp 11.Container_With_Most_Water/code.h
        12.Integer_to_Roman/code.cpp 12.Integer_to_Roman/code.h
        13.Roman_to_Integer/code.cpp 13.Roman_to_Integer/code.h
        14.Longest_Common_Prefix/code.cpp 14.Longest_Common_Prefix/code.h
        15.3Sum/code.cpp 15.3Sum/code.h
        16.3Sum_Closest/code.cpp 16.3Sum_Closest/code.h
        17.Letter_Combinations_of_a_Phone_Number/code.cpp 17.Letter_Combinations_of_a_Phone_Number/code.h
        18.4Sum/code.cpp 18.4Sum/code.h
        19.Remove_Nth_Node_From_End_of_List/code.cpp 19.Remove_Nth_Node_From_End_of_List/code.h
        20.Valid_Parentheses/code.cpp 20.Valid_Parentheses/code.h
        134.Gas_Station/code.cpp 134.Gas_Station/code.h
        135.Candy/code.cpp 135.Candy/code.h
        136.Single_Number/code.cpp 136.Single_Number/code.h
        137.Single_Number_II/code.cpp 137.Single_Number_II/code.h
        138.Copy_List_with_Random_Pointer/code.cpp 138.Copy_List_with_Random_Pointer/code.h
        139.Word_Break/code.cpp 139.Word_Break/code.h
        140.Word_Break_II/code.cpp 140.Word_Break_II/code.h
        141.Linked_List_Cycle/code.cpp 141.Linked_List_Cycle/code.h
        142.Linked_List_Cycle_II/code.cpp 142.Linked_List_Cycle_II/code.h
        143.Reorder_List/code.cpp 143.Reorder_List/code.h
        144.Binary_Tree_Preorder_Traversal/code.cpp 144.Binary_Tree_Preorder_Traversal/code.h
        145.Binary_Tree_Postorder_Traversal/code.cpp 145.Binary_Tree_Postorder_Traversal/code.h
        146.LRU_Cache/code.hpp
        147.Insertion_Sort_List/code.cpp 147.Insertion_Sort_List/code.h
        148.Sort_List/code.cpp 148.Sort_List/code.h
        149.Max_Points_on_a_Line/code.cpp 149.Max_Points_on_a_Line/code.h
        150.Evaluate_Reverse_Polish_Notation/code.cpp 150.Evaluate_Reverse_Polish_Notation/code.h
        151.Reverse_Words_in_a_String/code.cpp 151.Reverse_Words_in_a_String/code.h
        152.Maximum_Product_Subarray/code.cpp 152.Maximum_Product_Subarray/code.h
        153.Find_Minimum_in_Rotated_Sorted_Array/code.cpp 153.Find_Minimum_in_Rotated_Sorted_Array/code.h
        154.Find_Minimum_in_Rotated_Sorted_Array_II/code.cpp 154.Find_Minimum_in_Rotated_Sorted_Array_II/code.h
        155.Min_Stack/code.hpp
        )
add_library(LeetCodeLib ${SOURCE_FILES})
