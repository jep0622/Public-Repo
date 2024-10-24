type 'a stack = 'a list

let empty_stack : 'a stack = []

(* Push to front *)
let push (x: 'a) (s: 'a stack) : 'a stack =
  x :: s

(* Pop from front *)
let pop (s: 'a stack) : 'a option * 'a stack =
  match s with
  | [] -> (None, s)  (* Check empty *)
  | x :: xs -> (Some x, xs)  

(* Check empty *)
let is_empty (s: 'a stack) : bool =
  s = []

(* Print *)
let print_stack (s: 'a stack) : unit =
  let rec aux s =
    match s with
    | [] -> ()
    | x :: xs ->
        Printf.printf "%s " (string_of_int x);  
        aux xs
  in
  aux s;
  Printf.printf "\n"

(* Main *)
let () =
  let stack = empty_stack in
  let stack = push 1 stack in
  
  print_stack stack;  
  
  let (top_opt, stack) = pop stack in
  match top_opt with
  | None -> Printf.printf "Stack is empty
"
  | Some top -> Printf.printf "Popped: %d
" top;  

  print_stack stack;  

  Printf.printf "Stack is empty: %b
" (is_empty stack);  
