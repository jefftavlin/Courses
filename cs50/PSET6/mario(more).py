while True:
    height = input("Height: ")

    try:
        height = int(height)
        if height >= 1 and height <= 8:
            for i in range(1, height+1):
                spaces_count = (height - i) * " "
                hash_tags = i * "#"
                print(spaces_count + hash_tags + '  ' + "#" * i)
            break
    except ValueError:
        pass
