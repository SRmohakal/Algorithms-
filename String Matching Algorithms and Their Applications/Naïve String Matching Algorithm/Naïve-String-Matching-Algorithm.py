def naiveApproach(text,pattern):
    n=len(text)
    m=len(pattern)

    found=False
    for i in range(n-m+1): #Sliding over text
        match=True
        for j in range(m): #Checking each character
            if text[i+j]!=pattern[j]:
                match=False
                break      #if mismatch found then
        
        if match:
            print(f"Patern found at index {i}.")
            found=True
    
    if not found:
        print("Pattern is not found.")


if __name__=="__main__":
    text=input("Enter the text: ")
    pattern=input("Enter the pattern: ")
    naiveApproach(text,pattern)
