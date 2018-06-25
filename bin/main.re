open Entry;
open Date_action;
open Helpers;
open Cmdliner;


let journal = (verbose) =>
    `Ok(
        Printf.printf(
            "verbose = %b\n",
            verbose
        )
    );


let verbose = {
    let doc = "Run program in verbose mode.";
    Arg.(value & flag & info(["v", "verbose"], ~doc));
};

let cmd = {
    let doc = "Create journal entries.";
    let exits = Term.default_exits;
    let man = [`S(Manpage.s_bugs), `P("Email them to femi@femiagbabiaka.xyz")];
    let man_xrefs = [];
    (
        Term.(ret(const(journal) $ verbose)),
        Term.info("journal", ~version="v0.0.1", ~doc, ~exits, ~man, ~man_xrefs)
    );
};

let () =
    Term.(exit @@ eval(cmd));