import os


def merge_files_to_one(include_dir, src_dir, output_file):
    """
    Merge all .h files from include_dir and all .cpp files from src_dir
    into a single output file.
    """
    with open(output_file, 'w', encoding='utf-8') as outfile:
        # Process .h files from include directory
        outfile.write("=" * 50 + "\n")
        outfile.write("HEADER FILES (.h) FROM INCLUDE DIRECTORY\n")
        outfile.write("=" * 50 + "\n\n")

        if os.path.exists(include_dir):
            h_files = [f for f in os.listdir(include_dir) if f.endswith('.h')]
            h_files.sort()  # Sort files alphabetically

            for h_file in h_files:
                file_path = os.path.join(include_dir, h_file)
                outfile.write(f"File: {h_file}\n")
                outfile.write("-" * 50 + "\n")

                try:
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        content = infile.read()
                        outfile.write(content)
                except UnicodeDecodeError:
                    # Try with a different encoding if utf-8 fails
                    try:
                        with open(file_path, 'r', encoding='latin-1') as infile:
                            content = infile.read()
                            outfile.write(content)
                    except Exception as e:
                        outfile.write(f"Error reading file: {str(e)}\n")

                outfile.write("\n\n")
        else:
            outfile.write(f"Directory {include_dir} does not exist.\n\n")

        # Process .cpp files from src directory
        outfile.write("=" * 50 + "\n")
        outfile.write("SOURCE FILES (.cpp) FROM SRC DIRECTORY\n")
        outfile.write("=" * 50 + "\n\n")

        if os.path.exists(src_dir):
            cpp_files = [f for f in os.listdir(src_dir) if f.endswith('.cpp')]
            cpp_files.sort()  # Sort files alphabetically

            for cpp_file in cpp_files:
                file_path = os.path.join(src_dir, cpp_file)
                outfile.write(f"File: {cpp_file}\n")
                outfile.write("-" * 50 + "\n")

                try:
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        content = infile.read()
                        outfile.write(content)
                except UnicodeDecodeError:
                    # Try with a different encoding if utf-8 fails
                    try:
                        with open(file_path, 'r', encoding='latin-1') as infile:
                            content = infile.read()
                            outfile.write(content)
                    except Exception as e:
                        outfile.write(f"Error reading file: {str(e)}\n")

                outfile.write("\n\n")
        else:
            outfile.write(f"Directory {src_dir} does not exist.\n\n")


if __name__ == "__main__":
    include_directory = "include"
    src_directory = "src"
    output_filename = "result.txt"

    merge_files_to_one(include_directory, src_directory, output_filename)
    print(f"All files have been merged into {output_filename}")