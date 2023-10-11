use std::env;
use std::fs::File;
use std::io::prelude::*;
use std::io::{self, BufReader};

fn main() -> io::Result<()> {
    let args: Vec<String> = env::args().skip(1).collect();

    if args.is_empty() {
        println!("Provide an input file");
        return Ok(());
    }

    let file = File::open(&args[0])?;
    let reader = BufReader::new(file);

    for line in reader.lines() {
        match line {
            Ok(line) => {
                if args[1] == "1" {
                    part1(line);
                } else {
                    part2(line);
                }
            }
            Err(e) => {
                panic!("Error reading line: {}", e);
            }
        }
    }

    Ok(())
}

fn part1(input: String) {
    let mut res = 0;

    for c in input.chars() {
        if c.to_string() == "(" {
            res += 1;
        } else {
            res -= 1;
        }
    }

    println!("{}", res);
}

fn part2(input: String) {
    let mut floor = 0;

    for (idx, c) in input.chars().enumerate() {
        if c.to_string() == "(" {
            floor += 1;
        } else {
            floor -= 1;
        }

        if floor < 0 {
            println!("{}", idx + 1);

            break;
        }
    }
}
