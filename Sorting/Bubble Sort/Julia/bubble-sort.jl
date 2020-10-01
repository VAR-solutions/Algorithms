# Bubble Sort is the simplest sorting algorithm that works by 
# repeatedly swapping the adjacent elements if they are in wrong order.

function swap!{T}(x::AbstractArray{T}, a::T, b::T)

  tmp = x[a]
  x[a] = x[b]
  x[b] = tmp
  return x

end

function bubblesort!{T}(x::AbstractArray{T})

  for i in 2:length(x)
    for j in 1:length(x)-1
      if x[j] > x[j+1]
        swap!(x, j, j+1)
      end
    end
  end

  return x
end

x = [10,2,5,1,3,0]

println(bubblesort!(x))