#include <iostream>
#include <chrono>
#include <cassert>
#include <random>
#include <iostream>

namespace matrix_library {
    /**
     * @brief Class that combines working with matrices.
     * @details Is designed to protect the user from working with raw pointers,
     * @details combine methods for working with matrices in a single namespace.
     */
    class Matrix {
    public:
        /**
         * @brief Constructor to refer to a submatrix of an existing matrix.
         * @param original The original matrix in which we select the submatrix.
         * @param row_count The number of rows in the submatrix.
         * @param column_count The number of columns in the submatrix.
         * @param offset_x Horizontal offset(in standard notation) of the submatrix in the source matrix.
         * @param offset_y Vertical offset(in standard notation) of the submatrix in the source matrix.
         */
        Matrix(const Matrix& original, size_t row_count, size_t column_count, size_t offset_x = 0, size_t offset_y = 0);

        /**
         * @brief Constructor that allocates memory for the matrix and fills the matrix with zeros.
         * @param row_count The number of rows in the matrix.
         * @param column_count The number of columns in the matrix.
         */
        Matrix(size_t row_count, size_t column_count);

        /**
         * @brief Destructor. Frees memory if it was allocated in the constructor.
         */
        ~Matrix();

        /**
         * @brief Copy constructor.
         * @details Allocates memory for the new matrix and copies the elements.
         * @param Other the matrix to be copied.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Move constructor.
         * @details If another matrix owns memory with elements, this ownership will be transferred.
         * @details If another matrix points to someone else's memory, new memory will be allocated for the new matrix.
         * @param Other matrix to create a copy of.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Assignment operator without transferring data ownership.
         * @param rhs Assignable value.
         * @return Link to the current matrix.
         */
        Matrix& operator=(const Matrix& rhs);

        /**
         * @brief An assignment operator that transfers ownership of data if the second operand owns it.
         * @param rhs Assignable value.
         * @return Link to the current matrix.
         */
        Matrix& operator=(Matrix&& rhs) noexcept;


        inline float& get_element(size_t row_index, size_t column_index) {
            return data_[(offset_y_ + row_index) * original_column_count_ + offset_x_ + column_index];
        }

        /**
         * @brief Select the element to write the value to.
         * @param row_index Index of the row of the element in the matrix.
         * @param column_index Index of the element column in the matrix.
         * @return Link to the selected item.
         */
        inline const float& get_element(size_t row_index, size_t column_index) const {
            return data_[(offset_y_ + row_index) * original_column_count_ + offset_x_ + column_index];
        }

        /**
         * @brief Operator for element-wise matrix summation.
         * @param rhs The second term.
         * @return Sum of matrices.
         */
        Matrix operator+(const Matrix &rhs) const;

        /**
         * @brief Operator for element-wise matrix subtraction.
         * @param rhs Deductible.
         * @return Matrix difference.
         */
        Matrix operator-(const Matrix &rhs) const;

        /**
         * @brief Operator for adding another matrix element-by-element to this matrix.
         * @param rhs The second term.
         * @return Reference to the current matrix containing the sum of the matrices.
         */
        Matrix& operator+=(const Matrix& rhs);

        /**
         * @brief Operator for element-by-element subtraction of another matrix from this matrix.
         * @param rhs Deductible.
         * @return Link to the current matrix containing the matrix difference.
         */
        Matrix& operator-=(const Matrix& rhs);

        /**
         * @brief Fills the matrix with random values.
         */
        void initialize_randomly();

        /**
         * @brief Fills the matrix with zeros.
         */
        void initialize_zeros();

        /**
         * @brief Changes the size of the matrix by adding zeros or cutting edges.
         * @details Only for matrices that own memory.
         * @param new_row_count New number of rows.
         * @param new_column_count New number of columns.
         */
        void resize(size_t new_row_count, size_t new_column_count);

        /**
         * @brief Get a pointer to the memory that stores the matrix elements.
         * @return Pointer to memory with matrix elements.
         */
        float* get_data() const;

        /**
         * @brief Get the number of rows in the matrix.
         * @return The number of rows in the matrix.
         */
        size_t get_row_count() const;

        /**
         * @brief Get the number of columns in the matrix.
         * @return The number of columns in the matrix.
         */
        size_t get_column_count() const;

        /**
         * @brief Print the matrix to the output stream.
         * @param stream The output stream.
         */
        void print(std::ostream &stream = std::cout) const;

    private:
        /**
         * @brief Pointer to the memory where matrix elements are stored.
         * @details Memory can be allocated both inside and outside of this class. Different constructors are used for different purposes.
         */
        float *data_{nullptr};

        /**
         * @brief number of matrix rows.
         */
        size_t row_count_{0};
        /**
         * @brief The number of columns in the matrix.
         */
        size_t column_count_{0};

        /**
         * @brief False if the matrix owns memory with elements, true if it only points to this memory.
         * @details This class can be used in two ways:
         * @details We can allocate memory in the constructor, free it in the destructor.
         * @details We can refer to a submatrix of an existing matrix that is already stored in memory.
         */
        bool is_pointer_{false};

        /**
         * @brief The offset in the row(by columns / horizontally in the standard matrix entry) where the data lies relative to the data_ pointer.
         * @details If this matrix is a submatrix of another matrix, then you must specify the memory offset where the submatrix is located.
         */
        size_t offset_x_{0};
        /**
         * @brief The offset in the column(row-wise / vertical for standard matrix entry) that the data is based on relative to the data_ pointer.
         * @details If this matrix is a submatrix of another matrix, then you must specify the memory offset where the submatrix is located.
         */
        size_t offset_y_{0};

        /**
         * @brief Number of rows in the original matrix at data_.
         * @details If this matrix is a submatrix of another matrix, then you need to know the original number of rows to correctly address the elements.
         */
        size_t original_row_count_{0};

        /**
         * @brief The number of columns in the original matrix at data_.
         * @details If this matrix is a submatrix of another matrix, then you need to know the original number of columns to correctly address the elements.
         */
        size_t original_column_count_{0};
    };


    class MatrixMultiplier{
    public:
        /**
         * @brief Matrix multiplication by defining the product of matrices.
         * @param lhs The first multiplier.
         * @param rhs The second multiplier.
         * @param result Product of matrices.
         */
        static void multiplication_by_definition(const Matrix& lhs, const Matrix& rhs, Matrix& result);

        /**
         * @brief Matrix multiplication by defining the product of matrices.
         * @param lhs The first multiplier.
         * @param rhs The second multiplier.
         * @return the Product of matrices.
         */
        static Matrix multiplication_by_definition(const Matrix& lhs, const Matrix& rhs);

        /**
         * @brief Matrix multiplication using the Winograd-Strassen algorithm.
         * @details Only for square matrices.
         * @details Algorithm wrapper.
         * @param lhs The first multiplier.
         * @param rhs The second multiplier.
         * @return the Product of matrices.
         */
        static Matrix multiplication_strassen(Matrix& lhs, Matrix& rhs);
    private:
        /**
         * @brief Rounded up to an integer base 2 logarithm.
         * @details Uses knowledge about the representation of floating-point numbers in memory.
         * @details Read more: https://ru.wikipedia.org/wiki/Число_двойной_точности
         * @param number The number from which you want to take the base 2 logarithm.
         * @return The logarithm value rounded up to an integer.
         */
        static size_t round_log2(size_t number);

        /**
         * @brief Matrix multiplication using the Winograd-Strassen algorithm.
         * @details Only for square matrices.
         * @details Recursive part of the algorithm.
         * @param lhs The first multiplier.
         * @param rhs The second multiplier.
         * @param result Product of matrices.
         */
        static void multiplication_strassen_implementation(
                const Matrix& lhs, const Matrix& rhs, Matrix& result);
    };


// Implementations

    Matrix::Matrix(const Matrix& original, size_t row_count, size_t column_count, size_t offset_x, size_t offset_y) :
            data_(original.data_),
            row_count_(row_count),
            column_count_(column_count),
            is_pointer_(true),
            offset_x_(original.offset_x_ + offset_x),
            offset_y_(original.offset_y_ + offset_y),
            original_row_count_(original.original_row_count_),
            original_column_count_(original.original_column_count_){
        assert(offset_x + column_count_ <= original_column_count_);
        assert(offset_y + row_count_ <= original_row_count_);
    }

    Matrix::Matrix(size_t row_count, size_t column_count) :
            data_(new float[row_count * column_count]),
            row_count_(row_count),
            column_count_(column_count),
            is_pointer_(false),
            offset_x_(0),
            offset_y_(0),
            original_row_count_(row_count),
            original_column_count_(column_count){
        initialize_zeros();
    }

    Matrix::~Matrix() {
        if (!is_pointer_){
            delete[] data_;
        }
    }

    Matrix::Matrix(const Matrix &other) {
        is_pointer_ = false;
        row_count_ = other.row_count_;
        column_count_ = other.column_count_;
        original_row_count_ = row_count_;
        original_column_count_ = column_count_;
        data_ = new float[row_count_ * column_count_];

        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                get_element(i, j) = other.get_element(i, j);
            }
        }
    }

    Matrix::Matrix(Matrix&& other) noexcept {
        is_pointer_ = false;
        row_count_ = other.row_count_;
        column_count_ = other.column_count_;
        original_row_count_ = row_count_;
        original_column_count_ = column_count_;

        if (!other.is_pointer_) {
            data_ = other.data_;
            other.data_ = nullptr;
        } else {
            data_ = new float[row_count_ * column_count_];

            for (size_t i = 0; i < row_count_; ++i) {
                for (size_t j = 0; j < column_count_; ++j) {
                    get_element(i, j) = other.get_element(i, j);
                }
            }
        }
    }

    Matrix &Matrix::operator=(const Matrix &rhs) {
        if (this == &rhs){
            return *this;
        }
        if (!is_pointer_) {
            delete[] data_;
            row_count_ = rhs.row_count_;
            column_count_ = rhs.column_count_;
            original_row_count_ = row_count_;
            original_column_count_ = column_count_;
            data_ = new float[row_count_ * column_count_];
            for (size_t i = 0; i < row_count_; ++i) {
                for (size_t j = 0; j < column_count_; ++j) {
                    get_element(i, j) = rhs.get_element(i, j);
                }
            }
        } else {
            assert(row_count_ == rhs.row_count_);
            assert(column_count_ == rhs.column_count_);

            for (size_t i = 0; i < row_count_; ++i) {
                for (size_t j = 0; j < column_count_; ++j) {
                    get_element(i, j) = rhs.get_element(i, j);
                }
            }
        }
        return *this;
    }

    Matrix &Matrix::operator=(Matrix&& rhs) noexcept {
        if (this == &rhs){
            return *this;
        }
        if (!is_pointer_ && !rhs.is_pointer_) {
            delete[] data_;
            row_count_ = rhs.row_count_;
            column_count_ = rhs.column_count_;
            original_row_count_ = row_count_;
            original_column_count_ = column_count_;
            data_ = rhs.data_;
            rhs.data_ = nullptr;
        } else {
            assert(row_count_ == rhs.row_count_);
            assert(column_count_ == rhs.column_count_);

            for (size_t i = 0; i < row_count_; ++i) {
                for (size_t j = 0; j < column_count_; ++j) {
                    get_element(i, j) = rhs.get_element(i, j);
                }
            }
        }
        return *this;
    }

    Matrix Matrix::operator+(const Matrix &rhs) const {
        assert(row_count_ == rhs.row_count_);
        assert(column_count_ == rhs.column_count_);

        Matrix result(row_count_, column_count_);
        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                result.get_element(i, j) = get_element(i, j) + rhs.get_element(i, j);
            }
        }

        return result;
    }

    Matrix Matrix::operator-(const Matrix &rhs) const {
        assert(row_count_ == rhs.row_count_);
        assert(column_count_ == rhs.column_count_);

        Matrix result(row_count_, column_count_);
        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                result.get_element(i, j) = get_element(i, j) - rhs.get_element(i, j);
            }
        }

        return result;
    }

    Matrix &Matrix::operator+=(const Matrix &rhs) {
        assert(row_count_ == rhs.row_count_);
        assert(column_count_ == rhs.column_count_);

        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                get_element(i, j) += rhs.get_element(i, j);
            }
        }

        return *this;
    }

    Matrix &Matrix::operator-=(const Matrix &rhs) {
        assert(row_count_ == rhs.row_count_);
        assert(column_count_ == rhs.column_count_);

        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                get_element(i, j) -= rhs.get_element(i, j);
            }
        }

        return *this;
    }

    void Matrix::initialize_randomly() {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<float> dis(0.0f, 1.0f);

        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                get_element(i, j) = dis(gen);
            }
        }
    }

    void Matrix::initialize_zeros() {
        for (int i = 0; i < row_count_; ++i) {
            for (int j = 0; j < column_count_; ++j) {
                get_element(i, j) = 0.0f;
            }
        }
    }

    void Matrix::resize(size_t new_row_count, size_t new_column_count) {
        assert(!is_pointer_);

        if ((new_row_count == row_count_) && (new_column_count == column_count_)) {
            return;
        }

        float* new_data = new float[new_row_count * new_column_count];
        for (size_t i = 0; i < new_row_count; ++i) {
            for (size_t j = 0; j < new_column_count; ++j) {
                if ((i < row_count_) && (j < column_count_)) {
                    new_data[i * new_column_count + j] = get_element(i, j);
                } else {
                    new_data[i * new_column_count + j] = 0.0f;
                }
            }
        }

        delete[] data_;
        data_ = new_data;

        row_count_ = new_row_count;
        column_count_ = new_column_count;
        original_row_count_ = row_count_;
        original_column_count_ = column_count_;
    }

    float* Matrix::get_data() const {
        return data_;
    }

    size_t Matrix::get_row_count() const {
        return row_count_;
    }

    size_t Matrix::get_column_count() const {
        return column_count_;
    }

    void Matrix::print(std::ostream &stream) const {
        stream << std::endl;
        for (size_t i = 0; i < row_count_; ++i) {
            for (size_t j = 0; j < column_count_; ++j) {
                stream << get_element(i, j) << " ";
            }
            stream << std::endl;
        }
        stream << std::endl;
    }


    void MatrixMultiplier::multiplication_by_definition(const Matrix &lhs, const Matrix &rhs, Matrix &result) {
        assert(lhs.get_column_count() == rhs.get_row_count());
        assert(lhs.get_row_count() == result.get_row_count());
        assert(rhs.get_column_count() == result.get_column_count());

        result.initialize_zeros();

        for (size_t k = 0; k < lhs.get_column_count(); k++)
        {
            for (size_t i = 0 ; i < lhs.get_row_count(); i++)
            {
                for (size_t j = 0;  j < rhs.get_column_count(); j++)
                {
                    result.get_element(i, j) += lhs.get_element(i, k) * rhs.get_element(k, j);
                }
            }
        }
    }

    Matrix MatrixMultiplier::multiplication_by_definition(const Matrix &lhs, const Matrix &rhs) {
        assert(lhs.get_column_count() == rhs.get_row_count());

        Matrix result(lhs.get_row_count(), rhs.get_column_count());
        multiplication_by_definition(lhs, rhs, result);
        return result;
    }

    Matrix MatrixMultiplier::multiplication_strassen(Matrix &lhs, Matrix &rhs) {
        assert(lhs.get_row_count() == lhs.get_column_count());
        assert(rhs.get_row_count() == rhs.get_column_count());
        assert(lhs.get_column_count() == rhs.get_row_count());

        size_t matrix_size = lhs.get_row_count();
        size_t increased_matrix_size = static_cast<size_t>(std::lround(std::pow(2.0, static_cast<double>(round_log2(matrix_size)))));

        lhs.resize(increased_matrix_size, increased_matrix_size);
        rhs.resize(increased_matrix_size, increased_matrix_size);

        Matrix result(lhs.get_row_count(), rhs.get_column_count());

        multiplication_strassen_implementation(lhs, rhs, result);

        lhs.resize(matrix_size, matrix_size);
        rhs.resize(matrix_size, matrix_size);
        result.resize(matrix_size, matrix_size);

        return result;
    }

    size_t MatrixMultiplier::round_log2(size_t number) {
        double x = static_cast<double>(number - 1);  // if you remove "- 1", then "not less" in the description should be replaced with "more"
        auto answer = reinterpret_cast<unsigned int *>(&x);
        ++answer;
        return static_cast<size_t>(((*answer & 0x7FF00000) >> 20) - 1022);
    }

    void MatrixMultiplier::multiplication_strassen_implementation(const Matrix &lhs, const Matrix &rhs, Matrix &result) {
        /**
         * Description of algorithm: https://ru.wikipedia.org/wiki/Алгоритм_Штрассена
         * Generalization of the Karatsuba matrix multiplication method.
         * Modification of the Strassen algorithm, which requires 7 multiplications and 15 additions (instead of 18 for the usual Strassen algorithm).
         * Time complexity O(n^2.81)
         */
        static const size_t MATRIX_SIZE_EFFICIENT_BOUND = 64;  // If the matrix is smaller than this size, it is multiplied by definition.

        size_t matrix_size = lhs.get_row_count();
        if (matrix_size <= MATRIX_SIZE_EFFICIENT_BOUND) {
            multiplication_by_definition(lhs, rhs, result);
        } else {
            Matrix lhs11(lhs, matrix_size / 2, matrix_size / 2, 0, 0);
            Matrix lhs12(lhs, matrix_size / 2, matrix_size / 2, matrix_size / 2, 0);
            Matrix lhs21(lhs, matrix_size / 2, matrix_size / 2, 0, matrix_size / 2);
            Matrix lhs22(lhs, matrix_size / 2, matrix_size / 2, matrix_size / 2, matrix_size / 2);

            Matrix rhs11(rhs, matrix_size / 2, matrix_size / 2, 0, 0);
            Matrix rhs12(rhs, matrix_size / 2, matrix_size / 2, matrix_size / 2, 0);
            Matrix rhs21(rhs, matrix_size / 2, matrix_size / 2, 0, matrix_size / 2);
            Matrix rhs22(rhs, matrix_size / 2, matrix_size / 2, matrix_size / 2, matrix_size / 2);

            Matrix result11(result, matrix_size / 2, matrix_size / 2, 0, 0);
            Matrix result12(result, matrix_size / 2, matrix_size / 2, matrix_size / 2, 0);
            Matrix result21(result, matrix_size / 2, matrix_size / 2, 0, matrix_size / 2);
            Matrix result22(result, matrix_size / 2, matrix_size / 2, matrix_size / 2, matrix_size / 2);

            auto s1 = lhs21 + lhs22;
            auto s2 = s1 - lhs11;
            auto s3 = lhs11 - lhs21;
            auto s4 = lhs12 - s2;

            auto s5 = rhs12 - rhs11;
            auto s6 = rhs22 - s5;
            auto s7 = rhs22 - rhs12;
            auto s8 = s6 - rhs21;

            Matrix p1(s2.get_row_count(), s6.get_column_count());
            multiplication_strassen_implementation(s2, s6, p1);
            Matrix p2(lhs11.get_row_count(), rhs11.get_column_count());
            multiplication_strassen_implementation(lhs11, rhs11, p2);
            Matrix p3(lhs12.get_row_count(), rhs21.get_column_count());
            multiplication_strassen_implementation(lhs12, rhs21, p3);
            Matrix p4(s3.get_row_count(), s7.get_column_count());
            multiplication_strassen_implementation(s3, s7, p4);
            Matrix p5(s1.get_row_count(), s5.get_column_count());
            multiplication_strassen_implementation(s1, s5, p5);
            Matrix p6(s4.get_row_count(), rhs22.get_column_count());
            multiplication_strassen_implementation(s4, rhs22, p6);
            Matrix p7(lhs22.get_row_count(), s8.get_column_count());
            multiplication_strassen_implementation(lhs22, s8, p7);

            auto t1 = p1 + p2;
            auto t2 = t1 + p4;

            result11 = p2 + p3;
            result12 = t1 + p5 + p6;
            result21 = t2 - p7;
            result22 = t2 + p5;
        }
    }

}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Specify the size of the matrices.";
        return -1;
    }
    const size_t matrix_size = std::stoul(argv[1]);

    size_t experiments_count = 1;
    if (argc >= 3) {
        experiments_count = std::stoul(argv[2]);
    }

    matrix_library::Matrix a(matrix_size, matrix_size);
    a.initialize_randomly();
    matrix_library::Matrix b(matrix_size, matrix_size);
    b.initialize_randomly();

    std::vector<int64_t> durations_by_definition;
    for (int i = 0; i < experiments_count; ++i) {
        auto begin = std::chrono::steady_clock::now();
        auto c = matrix_library::MatrixMultiplier::multiplication_by_definition(a, b);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        durations_by_definition.push_back(elapsed_us.count());
    }
    auto average_duration_by_definition = std::accumulate(durations_by_definition.begin(), durations_by_definition.end(), 0.0) / durations_by_definition.size();

    std::vector<int64_t> durations_strassen;
    for (int i = 0; i < experiments_count; ++i) {
        auto begin = std::chrono::steady_clock::now();
        auto c = matrix_library::MatrixMultiplier::multiplication_strassen(a, b);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        durations_strassen.push_back(elapsed_us.count());
    }
    auto average_duration_strassen = std::accumulate(durations_strassen.begin(), durations_strassen.end(), 0.0) / durations_strassen.size();

    std::cout << experiments_count << " launches were carried out.\n";
    std::cout << "The multiplication by definition average duration of two " << matrix_size << "x" << matrix_size << " square matrices is " << static_cast<uint64_t>(average_duration_by_definition) << " us.\n";
    std::cout << "The multiplication with Strassen's algorithm average duration of two " << matrix_size << "x" << matrix_size << " square matrices is " << static_cast<uint64_t>(average_duration_strassen) << " us.\n";

    return 0;
}