project(LeetCode)

# include test framework headers
include_directories(${PROJECT_SOURCE_DIR}/../include)

set(TEST_SOURCE_FILES
        main.cpp
        1.Two_Sum/test.cpp
        2.Add_Two_Numbers/test.cpp
        3.Longest_Substring_Without_Repeating_Characters/code.cpp
        4.Median_of_Two_Sorted_Arrays/test.cpp
        5.Longest_Palindromic_Substring/test.cpp
        6.ZigZag_Conversion/test.cpp
        7.Reverse_Integer/test.cpp
        8.String_to_Integer_atoi/test.cpp
        9.Palindrome_Number/test.cpp
        10.Regular_Expression_Matching/test.cpp
        11.Container_With_Most_Water/test.cpp
        12.Integer_to_Roman/test.cpp
        13.Roman_to_Integer/test.cpp
        14.Longest_Common_Prefix/test.cpp
        15.3Sum/test.cpp
        16.3Sum_Closest/test.cpp
        17.Letter_Combinations_of_a_Phone_Number/test.cpp
        18.4Sum/test.cpp
        19.Remove_Nth_Node_From_End_of_List/test.cpp
        134.Gas_Station/test.cpp
        135.Candy/test.cpp
        136.Single_Number/test.cpp
        137.Single_Number_II/test.cpp
        138.Copy_List_with_Random_Pointer/test.cpp
        139.Word_Break/test.cpp
        140.Word_Break_II/test.cpp
        141.Linked_List_Cycle/test.cpp
        142.Linked_List_Cycle_II/test.cpp
        143.Reorder_List/test.cpp
        144.Binary_Tree_Preorder_Traversal/test.cpp
        145.Binary_Tree_Postorder_Traversal/test.cpp
        146.LRU_Cache/test.cpp
        147.Insertion_Sort_List/test.cpp
        148.Sort_List/test.cpp
        149.Max_Points_on_a_Line/test.cpp
        150.Evaluate_Reverse_Polish_Notation/test.cpp
        151.Reverse_Words_in_a_String/test.cpp
        152.Maximum_Product_Subarray/test.cpp
        153.Find_Minimum_in_Rotated_Sorted_Array/test.cpp
        154.Find_Minimum_in_Rotated_Sorted_Array_II/test.cpp
        155.Min_Stack/test.cpp
        )

add_executable(LeetCodeTest ${TEST_SOURCE_FILES})

target_link_libraries(LeetCodeTest LeetCodeLib)
